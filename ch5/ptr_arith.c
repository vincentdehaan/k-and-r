#include <stdio.h>

int main(void)
{
  char chars[10];

  printf("Address of chars: %p\n", &chars[0]);
  printf("Address of chars: %p\n", chars);

  printf("Uninitialized array element char[3]: %i\n", chars[3]);

  int ints[10];

  printf("Address of ints: %p\n", ints);
  printf("Address of ints+1: %p\n", ints + 1);

  printf("Address of ints+20: %p\n", ints + 20);
  printf("Value of int[20] (non-existing): %i\n", *(ints + 20));

  /*
  Yields a segmentation fault for i > 500
  for(int i = 0; i < 1000 * 1000; i += 100)
  {
    printf("Value of int[20+%i] (non-existing): %i\n", i, *(ints + i));
  }
  */

  unsigned int ints2[4] = {0xAABB, 0xCCDD, 0xABCD, 0xCBDA};

  printf("Int value at ints[3]: %x\n", *((ints2 + 3))  );
  printf("Char value at ints[3]: %x\n", *((unsigned char*)(ints2 + 3)) );
}