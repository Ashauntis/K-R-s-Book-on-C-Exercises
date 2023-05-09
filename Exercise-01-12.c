#include <stdio.h>

#define OUT 123456
#define IN 987654

// Write a program that prints it's input one word per line
int main()
{
    char c;
    int space = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (space == OUT) {
                putchar('\n');
                space = IN;
            }
        } else {
            putchar(c);
            space = OUT;
        }
    }

    return 0;
}
