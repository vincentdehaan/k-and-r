#include <stdlib.h>
#include <stdio.h>

void main(void)
{
  char* prev;

  for(int i = 0; i < 1000*1000; i++)
  {
    char * ptr = malloc(1000*1000);
    printf("Pointer: %p\n", ptr);
    if(i > 1) printf("Diff: %i\n", (void*) ptr - (void*) prev);
    prev = ptr;
    if(i % 10000 == 0) getchar();
  }
  getchar();
}