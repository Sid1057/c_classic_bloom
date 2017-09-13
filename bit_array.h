#ifndef H_BIT_ARRAY
#define H_BIT_ARRAY

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
  uint8_t* data;
  uintmax_t size;
} bit_array;

void* create_bit_array(bit_array* array, uintmax_t size);
void destroy_bit_array(bit_array* array);
bool get_bit(bit_array* array, uintmax_t index);
void set_bit(bit_array* array, uintmax_t index);

#endif
