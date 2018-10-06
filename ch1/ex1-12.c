// Exercise 1-12

#include <stdio.h>

#define IN  1   /* inside a delimiter */
#define OUT 0   /* outside a delimiter */

main()
{
    int c, state;

    state = IN;
    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\t')
            state = IN;
        else if(state == IN){ // A new word starts here
            putchar('\n');
            putchar(c);
            state = OUT;
        }
    }
}