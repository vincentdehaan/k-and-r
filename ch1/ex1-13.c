// Exercise 1-13

#include <stdio.h>
#define IN  1   /* inside a delimiter */
#define OUT 0   /* outside a delimiter */
#define MAXLEN 20

main() {
    int c, i, j;
    int lengths[MAXLEN];
    int length;
    int state;

    for(i = 0; i < MAXLEN; ++i)
        lengths[i] = 0;

    state = IN;
    length = 0;
    while((c = getchar()) != EOF) {
        if((c == ' ' || c == '\t' || c == '\n') && state == OUT) { // A word ends here
            state = IN;
            if(length >= MAXLEN) printf("This word is too long!");
            else ++lengths[length];
        } else if(state == IN) { // A new word starts here
            state = OUT;
            length = 1;
        } else
            ++length;
    }

    if(state == OUT) { // In case the last word is directly followed by EOF
        if(length >= MAXLEN) printf("This word is too long!");
        else ++lengths[length];
    }

    for(i = 0; i < MAXLEN; ++i) {
        printf("Words of length %d: ", i);
        for(j = 0; j < lengths[i]; j++)
            putchar('=');
        putchar('\n');
    }
}