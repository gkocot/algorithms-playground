#include <stdio.h>

typedef unsigned __int128 uint128_t;

int lengthOfSubstring(char * s) {
    uint128_t unique_characters = 0;
    int substring_len = 0;
    
    while (*s) {
        uint128_t character_bit = ((uint128_t)1 << *s);
        if ((unique_characters & character_bit) == 0) {
            unique_characters |= character_bit;
            substring_len++;            
        }
        else {
            break;
        }
        s++;
    }

    return substring_len;
}

int lengthOfLongestSubstring(char * s){
    uint128_t unique_characters = 0;  
    int substring_len = 0;
    int substring_len_max = 0;
    int string_len = strlen(s);
    int i = 0;
    
    while (s[i] && (substring_len_max < (string_len - i))) {
        substring_len = lengthOfSubstring(&s[i]);
        if (substring_len > substring_len_max) {
            substring_len_max = substring_len;
        }
        i++;
    }

    return substring_len_max;
}

int main() {
    printf("%d\n", lengthOfLongestSubstring("abcad"));
    printf("%d\n", lengthOfLongestSubstring("abcadef"));
    return 0;
}