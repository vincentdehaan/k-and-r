// Exercise 1-9

#include <stdio.h>

main() {
    int c, space;

    space = 0;
    while((c = getchar()) != EOF) 
        if(c == ' ') {
            if(!space) {
                putchar(c);
                space = 1;
            }
        } else {
            putchar(c);
            space = 0;
        }
}