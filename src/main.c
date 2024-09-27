#include <stdint.h>
#include <stdio.h>
#include "include/binary_search.h"

int main(int argument_count, char** argument_vector) {
  int error = 0;
  (void) printf("%s] %s) %d- argument_count: %d\n", __FILE__, __FUNCTION__, __LINE__, argument_count);
  (void) temp();

  int search_space0[3] = {1, 2, 3};
  uint_fast16_t search_space_size0 = 3;
  int search_space1[7] = {-3, -2, -1, 0, 1, 2, 3};
  uint_fast16_t search_space_size1 = 7;

  int *search_spaces[] = { search_space0, search_space1};
  uint_fast16_t search_space_size[2] = { search_space_size0, search_space_size1};

  int_fast16_t search_value0 = 2;
  int_fast16_t search_value1 = 1;
  int_fast16_t search_value2 = 5;
  
  int_fast16_t search_index = 0;

  for(uint_fast16_t index = 0; index < 2; index++) {
    (void) printf("%d- search_space%ju: ",__LINE__, index);
    for(uint_fast16_t index2 = 0; index2 < search_space_size[index]; index2++) {
      (void) printf(" %d", search_spaces[index][index2]);
    }
    (void) printf("\n");
    (void) printf("Search value: %jd\n", search_value0);
    search_index = binarySearch(search_spaces[index],search_space_size[index], search_value0);
    (void) printf("found index: %jd\n", search_index);
    
    (void) printf("Search value: %jd\n", search_value1);
    search_index = binarySearch(search_spaces[index],search_space_size[index], search_value1);
    (void) printf("found index: %jd\n", search_index);
    
    (void) printf("Search value: %jd", search_value2);
    search_index = binarySearch(search_spaces[index],search_space_size[index], search_value2);
    (void) printf("found index: %jd\n", search_index);
  }

  return error;
}
