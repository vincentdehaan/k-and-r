// Exercise 1-13

#include <stdio.h>
#define CHARS 26 /* we will count only letters seperately */

main() {
    int c, i, j;
    int freqs[CHARS];
    int otherfreq;

    for(i = 0; i < CHARS; ++i)
        freqs[i] = 0;
    otherfreq = 0;

    while((c = getchar()) != EOF)
        if(c >= 'a' && c <= 'z')
            ++freqs[c - 'a'];
        else if(c >= 'A' && c <= 'Z')
            ++freqs[c - 'A'];
        else
            ++otherfreq;

    for(i = 0; i < CHARS; ++i) {
        printf("Occurence of char %c:           ", i + 'a');
        for(j = 0; j < freqs[i]; j++)
            putchar('=');
        putchar('\n');
    }
    printf("Occurence of other characters: ");
    for(j = 0; j < otherfreq; j++)
        putchar('=');
    putchar('\n');
}