/* Exercise 1-20 */

#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

void detab(char s[], char d[]);

main() {
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    char detabbed[MAXLINE];
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        detab(line, detabbed);
        printf("%s", detabbed);
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

void detab(char s[], char d[]) {
    int i, j;

    for(i = j = 0; s[i] != '\0'; i++)
        if(s[i] == '\t'){
            if(j % TABSTOP == 0) d[j++] = ' ';
            while(j % TABSTOP != 0)
                d[j++] = ' ';
        }
        else d[j++] = s[i];

    d[j] = '\0';
}