#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(int x){
    // max: 2^31 - 1 = 2147483647
    // min: -2^31 = -2147483648
    const int max_len = sizeof("-2147483648");
    char * str = malloc(max_len + 1);
    memset(str, 0, max_len + 1);
    sprintf(str, "%d", x);

    const int len = strlen(str);
    
    int i = x > 0 ? 0 : 1;
    int j = len - 1;
    char c;

    while ( i < j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }

    // max: 2^31 - 1 = 2147483647
    // min: -2^31 = -2147483648
    if (str[0] == '-') {
        if (len > 11 || ((len == 11) && (strcmp(&str[1], "2147483648") > 0))) { 
            return 0;
        }
    }
    else {
        if (len > 10 || ((len == 10) && (strcmp(str, "2147483647")) > 0)) { 
            return 0;
        }
    }

    return atoi(str);
}

int main() {
    //printf("%d\n", reverse(1563847412));
    //printf("%d\n", reverse(-2147483412));
    //printf("%d\n", reverse(2147483647));
    printf("%d\n", reverse(-2147483648));
}