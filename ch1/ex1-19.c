/* Exercise 1-18 */
/* The program prints all input lines that are longer than 8 (not 80!) characters */

#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[], char d[]);

main() {
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    char reversed[MAXLINE];
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse(line, reversed);
        printf("%s\n", reversed);
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

void reverse(char s[], char d[]) {
    int i = 0, j = 0;

    while(s[i] != '\0')
        ++i;

    d[i] = '\0';

    while(i > 0)
        d[j++] = s[--i];
}