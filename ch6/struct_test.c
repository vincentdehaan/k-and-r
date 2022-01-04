#include <stdio.h>

struct stct1 {
  unsigned int i;
  char c;
  unsigned int i2;
  char c2;
};

struct stct2 {
  unsigned int i;
  unsigned int i2;
  char c;
  char c2;
};

void main(void)
{
  printf("Size of stct1: %i\n", sizeof(struct stct1));
  printf("Size of stct2: %i\n", sizeof(struct stct2)); // The difference in size is caused by alignment
}