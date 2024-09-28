#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

void temp(void) {
  (void) printf("%s] %s) %d- Hello, Header!\n", __FILE__, __func__, __LINE__);
  return;
}

int_fast16_t binarySearch(int* search_space, const uint_fast16_t search_space_size, const int search_value) {
  enum search_enum {
    EQUAL_TO_MIDDLE = 1,
    GREATER_THAN_MIDDLE = 2,
    LESS_THAN_MIDDLE = 3
  };

  int_fast16_t found_index = -1;

  (void) assert(0 <= search_space_size);
  bool continue_searching = true;
  uint_fast16_t start_index = 0;
  uint_fast16_t end_index = search_space_size - 1;
  uint_fast8_t case_search_size = (end_index - start_index);
  uint_fast16_t middle_index = search_space_size / 2;
  
  uint_fast8_t find_area = (search_value == search_space[middle_index]) + (2*(search_value > search_space[middle_index])) + (3*(search_value < search_space[middle_index]));

/*   
 
  (void) printf("%d- middle_index: %ju\tstart_index: %ju\tend_index: %ju\tcase_search_size: %ju\tfind_area: %ju\n", 
    __LINE__, middle_index, start_index,end_index, case_search_size, find_area);
*/

  while(continue_searching) {
    switch(case_search_size) {
      case 0 : { 
        /*
          1 VALUE IN ARRAY 
        */
        if(search_value == search_space[middle_index]) {
          return middle_index;
        } else {
          return found_index;
        }
        break;
      };
      case 1 : {
        /*
          2 VALUES IN ARRAY
        */
        if(search_value == search_space[start_index]) {
          return 0;
        } else  {
          if(search_value == search_space[end_index]) {
            return 1; 
            } else {
              return found_index;}
        }
        break;
      };
      default : {
        /*
          MORE THAN 2 VALUES IN ARRAY
        */
        /* Find area
          1 -> the search value is at the middle value
          2 -> the search value is greater than the  middle value
          3 -> the search value is less than the middle value
          default -> this shouldn't happen
        */
        switch(find_area) {
          case EQUAL_TO_MIDDLE : {
            (void) printf("%d-\tfound at middle index: %ju\tmiddle index value: %d\n", __LINE__, middle_index, search_space[middle_index]);
            return middle_index;
            //found_index = middle_index;
            continue_searching = false;
            break;
          };
          case GREATER_THAN_MIDDLE : {
            (void) printf("%d-\tgreater than middle index: %ju\tmiddle index value: %d\n", __LINE__, middle_index, search_space[middle_index]);
            start_index = middle_index + 1;
            case_search_size = end_index - start_index;
            middle_index = (end_index - start_index) + middle_index;
            break;
          };
          case LESS_THAN_MIDDLE : {
            (void) printf("%d-\tless that middle index: %ju\tmiddle index value: %d\n", __LINE__, middle_index, search_space[middle_index]);
            end_index = middle_index - 1;
            case_search_size = end_index - start_index;
            middle_index = (end_index - start_index) + start_index;
            break;
          };
          default : {
            break;
          };
        }
        find_area = (search_value == search_space[middle_index]) + (2*(search_value > search_space[middle_index])) + (3*(search_value < search_space[middle_index]));
        case_search_size = end_index - start_index;
        break;
      }
      break;
    }
    //continue_searching = false;
  }
  return found_index;
}