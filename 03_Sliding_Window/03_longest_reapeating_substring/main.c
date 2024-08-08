#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int lengthOfLongestSubstring(char* s) {
    int charSet[128] = {0};
    int left = 0, maxLength = 0;
    
    for (int right = 0; s[right] != '\0'; ++right) {
        while (charSet[s[right]] > 0) {
            charSet[s[left]]--; 
            left++;
        }
        charSet[s[right]]++;
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}

// Example usage
int main() {
    char s1[] = "zxyzxyz";
    char s2[] = "xxxx";
    
    printf("Length of longest substring without duplicate characters in '%s': %d\n", s1, lengthOfLongestSubstring(s1));
    printf("Length of longest substring without duplicate characters in '%s': %d\n", s2, lengthOfLongestSubstring(s2));
    
    return 0;
}
