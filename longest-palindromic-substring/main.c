#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int palindromeLength(char * s, int left, int right) {
    while ((left >= 0) && (s[right] != 0) && (s[left] == s[right])) {
        left--;
        right++;
    }

    return right - left - 1;
}

// TBD Understand and use Manacher's Algorithm O(n)
char * longestPalindrome(char * s){
    int n = strlen(s);
    int len_max = 0;
    int start = 0;
    // int end = 0;

    for (int i = 0; i < n; ++i) {
        int len1 = palindromeLength(s, i, i);
        int len2 = palindromeLength(s, i, i+1);
        int len = len1 > len2 ? len1 : len2;

        if (len > len_max) {
            len_max = len;
            start = i - ((len - 1) / 2);
            // end = i + (len / 2);
        }
    }

    char * result = (char *)malloc(len_max + 1);
    memset(result, 0, len_max + 1);
    strncpy(result, &s[start], len_max);
    return result;
}

int main() {
    printf("%s\n", longestPalindrome("abc"));
    printf("%s\n", longestPalindrome("abbc"));
    printf("%s\n", longestPalindrome("eracecard"));
    return 0;
}