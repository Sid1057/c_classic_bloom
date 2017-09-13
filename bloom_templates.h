// #include "templates.h"
// CREATE_MACROS(TEMPLATE(BLOOM, T))
// #define BLOOM_##T

#include "bit_array.h"
#include "bloom_macros.h"
#include <stdint.h>
#include <stdlib.h>

typedef uintmax_t (*hash_function(T))(T);

typedef struct hash_func_node(T)
{
  struct hash_func_node(T) *next;
  hash_function(T) hash;
} hash_func_node(T);

void insert_hash_func_node(T)(hash_func_node(T)* head, hash_function(T));
void free_hash_func_list(T)(hash_func_node(T)* head);

typedef struct
{
  bit_array field;
  hash_function(T) hash;
  hash_func_node(T)* functions_list;
} bloom_filter(T);

void bloom_filter_init(T)(bloom_filter(T)* filter, uintmax_t size, int functions_count, ...);
void bloom_filter_destroy(T)(bloom_filter(T)* filter);
void bloom_filter_insert(T)(bloom_filter(T)* filter, T item);
bool bloom_filter_has(T)(bloom_filter(T)* filter, T item);

