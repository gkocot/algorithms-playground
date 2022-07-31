#include <stdio.h>

int roman_value(char c) {
switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int roman_to_int(char const * const roman) {
    int i = 0;
    int result = 0;

    int cur = roman_value(roman[i]);
    int next = roman_value(roman[i+1]);

    do {
        if (cur >= next) {
            result += cur;
        }
        else {
            result -= cur;
        }
        i++;
        cur = next;
        if (roman[i]) {
            next = roman_value(roman[i+1]);
        }
        else {
            break;
        }
    } while (1);
    return result;
}

int main() {
    printf("%d\n", roman_to_int("MMMCDXLIX"));
    printf("%d\n", roman_to_int("MCMXCIV")); //1994
    printf("%d\n", roman_to_int("XXXII"));
}