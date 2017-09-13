#include "bit_array.h"
#include "bloom_templates.h"

#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>

void insert_hash_func_node(T)(hash_func_node(T)* head, hash_function(T) hash)
{
  head->next = NULL;
  head->hash = hash;
}

void free_hash_func_list(T)(hash_func_node(T)* head)
{
  hash_func_node(T)* current = head;
  hash_func_node(T)* prev = NULL;
  while (current != NULL)
  {
    prev = current;
    current = current->next;
    free(prev);
  }
}

inline void bloom_filter_init(T)(bloom_filter(T)* filter, uintmax_t size, int functions_count, ...)
{
  assert(functions_count > 0);
  create_bit_array(&filter->field, size);
  va_list functions;
  va_start(functions, functions_count);

  filter->functions_list = malloc(sizeof(hash_func_node(T)));
  hash_func_node(T)* list = filter->functions_list;
  for (int i = 0; i < functions_count; ++i)
  {
    hash_function(T) hash = va_arg(functions, hash_function(T));

    list->next = malloc(sizeof(hash_func_node(T)));
    list = list->next;
    insert_hash_func_node(T)(list, hash);
    list->next = NULL;

  }

  va_end(functions);
}

inline void bloom_filter_destroy(T)(bloom_filter(T)* filter)
{
  destroy_bit_array(&filter->field);
  free_hash_func_list(T)(filter->functions_list);  
}

inline void bloom_filter_insert(T)(bloom_filter(T)* filter, T item)
{
  for (hash_func_node(T)* i = filter->functions_list->next; i != NULL; i = i->next)
  {
    set_bit(&filter->field, i->hash(item) % filter->field.size);
  }
}

inline bool bloom_filter_has(T)(bloom_filter(T)* filter, T item)
{
  for (hash_func_node(T)* i = filter->functions_list->next; i != NULL; i = i->next)
  {
    if (get_bit(&filter->field, i->hash(item) % filter->field.size) == false)
    {
      return false;
    }
  }

  return true;
}
