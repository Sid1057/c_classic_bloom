#include "bit_array.h"

#include <stdlib.h>

inline void* create_bit_array(bit_array* array, uintmax_t size)
{
  // TODO, CHECKING, MAYBE THIS IS A STUPID MISTAKE
  array->data = calloc(size, sizeof((size + 7) / 8));
  array->size = size;
  return array->data;
}

inline void destroy_bit_array(bit_array* array)
{
  free(array->data);
}

inline bool get_bit(bit_array* array, uintmax_t index)
{
  index %= array->size;
  return array->data[index / 8] & (1 << (index % 8));
}

inline void set_bit(bit_array* array, uintmax_t index)
{
  index %= array->size;
  array->data[index / 8] |= (1 << (index % 8));
}
