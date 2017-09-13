# Overview
My implementation of classic bloom filter in pure c.
You could use any type of data with it.
See usage.

### Usage
Edit bloom.h between bloom_macros.h including line and '#endif' line for supporting your data type like this:
```c
#define T YOUR_TYPE_OF_DATA_NUMBER_ONE
#include "bloom_templates.h"
#undef T

#define T YOUR_TYPE_OF_DATA_NUMBER_ONE
#include "bloom_templates.h"
#undef T
```
