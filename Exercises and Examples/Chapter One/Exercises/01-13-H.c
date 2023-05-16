// Write a program to print a histogram of the lengths of words in it's input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

#include <stdio.h>

#define OUT 123
#define IN 654
#define MAX_WORD_LENGTH 255

int main () {

    char c;
    int state, lengths[MAX_WORD_LENGTH];
    int count = 0;

    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        lengths[i] = 0;
    }

    while ((c = getchar()) != EOF ) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            if (count > 0 && count <= MAX_WORD_LENGTH) {
                lengths[count-1]++;
                count = 0;
            }
        } else {
            ++count;
            state = IN;
        }
    }

    if (count > 0 && count <= MAX_WORD_LENGTH) lengths[count-1]++;

    printf("A Histogram of the lengths of input words!\n");
    printf("------------------------------------------\n");
    for(int i = 0; i < MAX_WORD_LENGTH; i++) {
        if(lengths[i] > 0) {
            int count = 0;
            printf("%d", i+1);
            while (count < lengths[i]) {
                printf("#");
                ++count;
            }
            printf("\t%d\n", lengths[i]);
        }
    }
    return 1;
}