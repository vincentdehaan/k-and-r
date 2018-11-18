/* Exercise 1-18 */
/* The program prints all input lines that are longer than 8 (not 80!) characters */

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);

main() {
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    int discarded;
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        discarded = count_whitespace(line, len);
        if(discarded != len) {
            printf("%s", &line[discarded]);
        }
    }

    return 0;
}

/* get_line: read a line into s, return length 
   NOTE: we use get_line instead of getline because getline has been defined in
         the new version of stdio.h */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int count_whitespace(char s[], int len) {
    int c = 0, i;

    for(i = 0; i < len; ++i) {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') c++;
        else break;
    }

    return c;
}