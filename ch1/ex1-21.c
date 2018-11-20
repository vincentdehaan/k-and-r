/* Exercise 1-21 */

#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

void entab(char s[], char d[]);
int countspaces(char s[]);

main() {
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    char entabbed[MAXLINE];
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        entab(line, entabbed);
        printf("%s", entabbed);
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
// TODO
void entab(char s[], char d[]) {
    int i, j, c;

    for(i = j = 0; s[i] != '\0'; i++) {
        c = countspaces(&s[i]);
        printf("%d", c);
        if(c < 2) { // current char is no space or a single space
            d[j++] = s[i];
        } else if((i + 1) % TABSTOP + c < TABSTOP) { // not enough spaces for a tab
            d[j++] = s[i];
        } else { // insert a single tab (we could optimize this by inserting as many tabs as possible)
            d[j++] = '_';
            i += (i + 1) % TABSTOP - 1;
        }
    }
    
    d[j] = '\0';
}

int countspaces(char s[]) {
    int i;

    for(i = 0; s[i] == ' '; i++);

    return i;
}