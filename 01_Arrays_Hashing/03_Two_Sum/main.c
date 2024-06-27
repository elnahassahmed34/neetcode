#include <stdio.h>
#include <ctype.h> // for isalnum
#include <string.h> // for strlen

// Function to check if a string is a palindrome
int isPalindrome(char *s) {
    // Initialize pointers
    char *left = s;
    char *right = s + strlen(s) - 1;
    
    // Traverse the string
    while (left < right) {
        // Skip non-alphanumeric characters
        while (!isalnum(*left) && left < right) {
            left++;
        }
        while (!isalnum(*right) && left < right) {
            right--;
        }
        
        // Compare characters (case insensitive)
        if (tolower(*left) != tolower(*right)) {
            return 0; // Not a palindrome
        }
        
        // Move pointers inward
        left++;
        right--;
    }
    
    return 1; // Palindrome
}

int main() {
    // Test cases
    char s1[] = "Was it a car or a cat I saw?";
    char s2[] = "tab a cat";
    
    // Test and output results
    printf("Example 1: %s\n", isPalindrome(s1) ? "true" : "false");
    printf("Example 2: %s\n", isPalindrome(s2) ? "true" : "false");
    
    return 0;
}
