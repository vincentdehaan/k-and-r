#include <stdio.h>

int *prev;

void recurse(int);

void main(void)
{
  recurse(1);
}

void recurse(int i)
{
  // By increasing the size of this array, the stack frames get bigger.
  int arr[10000];
  printf("Step %i\n", i);
  // Note that we need to cast the pointers to void* to get the size in bytes.
  if(i > 1) printf("Pointer diff: %i\n", (void*)&i - (void*)prev);
  printf("Pointer: %p\n", &i);
  prev = &i;
  // With a stack frame size of 40kb, we get a segmentation fault at i = 209. Apparently the stack size =~ 8mb.
  if(i < 1000) recurse(i + 1);
}