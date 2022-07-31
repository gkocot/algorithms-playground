#include <stdio.h>
#include <string.h>

#define NOT_FOUND (-1)

int lengthOfLongestSubstring(char * s) {
    int substring_len_max = 0;
    int substring_len = 0;
    int start = 0;
    int end = 0;
    int char_map[128];

    memset(char_map, NOT_FOUND, sizeof(char_map));

    while (s[end]) {
        if (char_map[(int)s[end]] == NOT_FOUND) {
            substring_len++;
        }
        else {
            // remember length of the longest substring
            if (substring_len_max < substring_len) {
                substring_len_max = substring_len;
            }
            // slide the window start index until we find the repeating character
            while ((start != end) && (s[start] != s[end])) {
                char_map[(int)s[start++]] = NOT_FOUND;
            }
            char_map[(int)s[start++]] = NOT_FOUND;
            substring_len = end - start + 1;
        }
        char_map[(int)s[end]] = end;
        end++;
    }

    if (substring_len_max < substring_len) {
        substring_len_max = substring_len;
    }   

    return substring_len_max;
}

int main() {
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", lengthOfLongestSubstring("abba"));
    printf("%d\n", lengthOfLongestSubstring("nfpdmpi"));
    return 0;
}