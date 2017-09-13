#include "bloom.h"

#include <stdio.h>
#include <time.h>

uintmax_t my_hash(int i)
{
  return i;
}

uintmax_t my_hash2(int i)
{
  return i % 93;
}

int main(int argc, char* argv[])
{
  int filter_size = 1001;
  int insered_elements = 0;
  int founded_elements = 0;

  if (argc == 3)
  {
    // levels = 32;
    filter_size = atoi(argv[1]);
    // elements = atoi(argv[2]);
  }

  bloom_filter(int) my_bloom;
  bloom_filter_init(int)(&my_bloom, filter_size, 2, my_hash, my_hash2);

  for (int i = 0; i < filter_size; ++i)
  {
    if (i % 103 == 0)
    {
      bloom_filter_insert(int)(&my_bloom, i);
	  insered_elements++;
    }
  }

  for (int i = 0; i < filter_size; ++i)
  {
    if (bloom_filter_has(int)(&my_bloom, i))
    {
      printf("%d: %s\n", i, "maybe");
	  founded_elements++;
    }
  }

  printf("Size: %d.\nInserted: %d.\nFounded: %d\n",
         filter_size, insered_elements, founded_elements);

  bloom_filter_destroy(int)(&my_bloom);

  return 0;
}
