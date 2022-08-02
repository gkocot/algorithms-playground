int myAtoi(char * s) {
    int result = 0;
    int sign = 1;

    while (*s && (*s == ' ')) {
        s++;
    }

    if (*s && (*s == '-')) {
        sign = -1;
        s++;
    }
    else if (*s && (*s == '+')) {
        sign = 1;
        s++;
    }

    while (*s && (*s == '0')) {
        s++;
    }

    // max: 2^31 - 1 = 2147483647
    // min: -2^31 = -2147483648
    char * start;
    char * end;
    if (*s && ((*s >= '1') && (*s <= '9'))) {
        start = s;
        end = s + 1;
    }
    else {
        return 0;
    }

    while (*end && ((*end >= '0') && (*end <= '9'))) {
        end++;
    }

    if ((end - start) < 10) {
        while (start != end) {
            result = result * 10 + (*start - '0');
            start++;
        }
        result = sign * result;
    }
    else if ((end - start) == 10) {
        const char * max = sign == 1 ? "2147483647" : "2147483648";
        if (strcmp(start, max) >= 0) {
            result = sign == 1 ? 2147483647 : -2147483648;
        } 
        else {
            while (start != end) {
                result = result * 10 + (*start - '0');
                start++;
            }
            result = sign * result;
        }
    }
    else {
        result = sign == 1 ? 2147483647 : -2147483648;
    }

    return result;
}

int main() {
    printf("%d\n", myAtoi("-2147483648"));
    // printf("%d\n", myAtoi("  0000000000012345678"));   
    // printf("%d\n", myAtoi("    -2147483648"));
    // printf("%d\n", myAtoi("    -2147483649"));
    // printf("%d\n", myAtoi("    2147483647"));
    // printf("%d\n", myAtoi("    +2147483647"));
    // printf("%d\n", myAtoi("    2147483648"));
    return 0;
}