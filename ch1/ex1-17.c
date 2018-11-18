/* Exercise 1-17 */
/* The program prints all input lines that are longer than 8 (not 80!) characters */

#include <stdio.h>
#define MAXLINE 1000
#define THRESHOLD 8

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

main() {
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        if(len > THRESHOLD + 1)
            printf("%s", line);
    }

    return 0;
}

/* get_line: read a line into s, return length 
   NOTE: we use get_line instead of getline because getline has been defined in
         the new version of stdio.h */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}