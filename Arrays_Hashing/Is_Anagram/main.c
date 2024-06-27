#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if two strings are anagrams
bool isAnagram(const char* s, const char* t) {
    // If the lengths of the strings are not equal, they cannot be anagrams
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // Array to count the frequency of each character (assuming lowercase English letters)
    int charCount[26] = {0};

    // Count the frequency of each character in the first string
    for (int i = 0; s[i] != '\0'; ++i) {
        charCount[s[i] - 'a']++;
    }

    // Decrease the frequency for each character in the second string
    for (int i = 0; t[i] != '\0'; ++i) {
        charCount[t[i] - 'a']--;
    }

    // Check if all counts are zero
    for (int i = 0; i < 26; ++i) {
        if (charCount[i] != 0) {
            return false;
        }
    }

    // If we reach here, the strings are anagrams
    return true;
}

int main() {
    // Test case 1
    const char* s1 = "racecar";
    const char* t1 = "carrace";
    bool result1 = isAnagram(s1, t1);
    printf("Example 1: %s\n", result1 ? "true" : "false"); // Output: true

    // Test case 2
    const char* s2 = "jar";
    const char* t2 = "jam";
    bool result2 = isAnagram(s2, t2);
    printf("Example 2: %s\n", result2 ? "true" : "false"); // Output: false

    return 0;
}
