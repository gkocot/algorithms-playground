#include <stdio.h>

int roman_to_int(char const * const roman) {
    int i = 0;
    int prev = 1001;
    int result = 0;

    while (roman[i]) {
        switch (roman[i]) {
            case 'M':
                result += 1000;
                if (prev < 1000) {
                    result -= (2 * prev);
                }
                prev = 1000;
                break;
            case 'D':
                result += 500;
                if (prev < 500) {
                    result -= (2 * prev);
                }
                prev = 500;
                break;
            case 'C':
                result += 100;
                if (prev < 100) {
                    result -= (2 * prev);
                }
                prev = 100;
                break;
            case 'L':
                result += 50;
                if (prev < 50) {
                    result -= (2 * prev);
                }
                prev = 50;
                break;
            case 'X':
                result += 10;
                if (prev < 10) {
                    result -= (2 * prev);
                }
                prev = 10;
                break;
            case 'V':
                result += 5;
                if (prev < 5) {
                    result -= (2 * prev);
                }
                prev = 5;
                break;
            case 'I':
                result += 1;
                prev = 1;
                break;
        }
        i++;
    }
    return result;
}

int main() {
    printf("%d\n", roman_to_int("MMMCDXLIX"));
    printf("%d\n", roman_to_int("MCMXCIV")); //1994
    printf("%d\n", roman_to_int("XXXII"));
}