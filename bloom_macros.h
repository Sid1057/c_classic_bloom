#ifndef BLOOM_MACROS
#define BLOOM_MACROS

#include "templates.h"

#define bloom_filter_init(T) TEMPLATE(bloom_filter_init, T)
#define bloom_filter_destroy(T) TEMPLATE(bloom_filter_destroy, T)
#define bloom_filter_insert(T) TEMPLATE(bloom_filter_insert, T)
#define bloom_filter_has(T) TEMPLATE(bloom_filter_has, T)
#define hash_function(T) TEMPLATE(hash_function, T)
#define hash_func_node(T) TEMPLATE(hash_func_node, T)
#define bloom_filter(T) TEMPLATE(bloom_filter, T)
#define insert_hash_func_node(T) TEMPLATE(insert_hash_func_node, T)
#define free_hash_func_list(T) TEMPLATE(free_hash_func_list, T)

#endif
