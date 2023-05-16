// Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.

#include <stdio.h>

float convert_to_celsius(float);

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahr Celsius\n");
    while (fahr <= upper) {
        printf("%4.0f %7.1f\n", fahr, convert_to_celsius(fahr));
        fahr +=20;
    }
}

// function to convert fahr input to celsius output
float convert_to_celsius(float fahr) {
    float celsius = 0;
    celsius = (5.0/9.0) * (fahr-32.0);
    return celsius;
};