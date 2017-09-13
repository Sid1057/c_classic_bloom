#ifndef H_BLOOM_TEMPLATES
#define H_BLOOM_TEMPLATES

#include "bit_array.h"
#include <stdint.h>
#include <stdlib.h>

// #define T int

typedef uintmax_t (*hash_function)(T);

typedef struct hash_func_node
{
  struct hash_func_node *next;
  hash_function hash;
} hash_func_node;

void insert_hash_func_node(hash_func_node* head, hash_function);
void free_hash_func_list(hash_func_node* head);

typedef struct
{
  bit_array field;
  hash_function hash;
  hash_func_node* functions_list;
} bloom_filter;

void bloom_filter_init(bloom_filter* filter, uintmax_t size, int functions_count, ...);
void bloom_filter_destroy(bloom_filter* filter);
void bloom_filter_insert(bloom_filter* filter, T item);
bool bloom_filter_has(bloom_filter* filter, T item);

#endif
