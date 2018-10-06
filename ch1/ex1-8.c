// Exercise 1-8

#include <stdio.h>

/* count blanks, newlines and tabs in input */
main()
{
    int c, nl, tab, blank;

    nl = 0;
    tab = 0;
    blank = 0;
    while((c = getchar()) != EOF)
        if(c == '\n')
            ++nl;
        else if(c == '\t')
            ++tab;
        else if(c == ' ')
            ++blank;
    
    printf("Newlines: %d\nTabs: %d\nBlanks: %d\n", nl, tab, blank);
}