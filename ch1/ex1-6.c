// Exercise 1-6

#include <stdio.h>

main()
{
    int c;
    // Generate EOF in Linux with CTRL+D
    while(1) printf("getchar() != EOF: %d\n", getchar() != EOF);
}