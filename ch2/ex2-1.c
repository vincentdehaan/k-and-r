#include <stdio.h>

int main()
{
  printf("Data type sizes: \n");

// NOTE: This is not what the exercise dictates, but it is interesting to see.
  printf("int: %lu \n", sizeof (int));
  printf("long int: %lu \n", sizeof (long int));
  printf("short int: %lu \n", sizeof (short int));
  printf("float: %lu \n", sizeof (float));
  printf("double: %lu \n", sizeof (double));
  printf("long double: %lu \n", sizeof (long double));
  printf("int*: %lu \n", sizeof (int*));
  printf("char: %lu \n", sizeof (char));
  printf("char*: %lu \n", sizeof (char*));
}