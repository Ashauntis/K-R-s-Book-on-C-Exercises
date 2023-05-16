// The function getline required c to be declared as a char
// instead of an int as in the book to function correclty.
// This appears to be a change in the C language since the
// book was written or a change in the clang compiler.

#include <stdio.h>
#define MAXLINE 200 /* maximum input line size*/

int getline(char [], int );
void copy(char [], char []);

/* print longest input line */
int main()
{
    int len; /* current line length */
    int max = 0; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) /* there was a line */
        printf("%s", longest);
    else printf("No lines submitted");
    return 0;
}

/* getline: read a line into a, return length */
int getline(char s[], int lim)
{
    char c;
    int i;


    printf("Enter a line: ");

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';

    printf("Length: %d\n", i);

    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}