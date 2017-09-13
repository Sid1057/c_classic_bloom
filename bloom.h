#ifndef H_BLOOM
#define H_BLOOM

#include "templates.h"
#include "bloom_macros.h"
/*
  TODO DOC
*/

#define T char
#include "bloom_templates.h"
#undef T

#define T int
#include "bloom_templates.h"
#undef T

#endif
