/* Exercise 1-16 */

#include <stdio.h>
#define MAXLINE 10 /* Use a smaller value for testing purposes */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main() {
    int len;        /* current line length */
    int max;        /* maximum length seen so far */
    int templen;
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */
    char discard[MAXLINE];  /* put the discarded chars here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        /* At this point, line either ends with \n or not; in the latter case,
            we need to call get_line again without overwriting line. */
        if (len == MAXLINE - 1 && line[MAXLINE - 1] != '\n') { /* This means there is more on this line */
            while((templen = get_line(discard, MAXLINE)) > 0) {
                len = len + templen;
                if(templen != MAXLINE - 1 || discard[MAXLINE - 1] == '\n') break;
            }
        } 
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if(max > 0) /* there was a line */
        printf("%s (%d chars)", longest, max);

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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}