#include <stdio.h>

char const * const ones_to_romans[] = {
    "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
};

char const * const tens_to_romans[] = {
    "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
};

char const * const hundreds_to_romans[] = {
    "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
};

char const * const thousands_to_romans[] = {
    "", "M", "MM", "MMM"
};

char * int_to_roman(int num) {
    char * roman = malloc(4 * 4 * sizeof(char));

    int ones = num %  10;
    int tens = (num / 10) % 10;
    int hundreds = (num / 100) % 10;
    int thousands = (num / 1000) % 10;

    sprintf(roman, "%s%s%s%s", thousands_to_romans[thousands], hundreds_to_romans[hundreds], tens_to_romans[tens], ones_to_romans[ones]);
    return roman;
}

int main() {
    printf("%s\n", int_to_roman(3449));
    printf("%s\n", int_to_roman(9));
    printf("%s\n", int_to_roman(32));
}