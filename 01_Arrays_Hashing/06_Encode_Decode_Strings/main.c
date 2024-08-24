#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to encode the list of strings
char* encode(char** strs, int strsSize) {
    char* encoded = (char*)malloc(MAX_SIZE * sizeof(char));
    encoded[0] = '\0'; // Initialize to an empty string

    for (int i = 0; i < strsSize; i++) {
        char buffer[10];
        sprintf(buffer, "%d#", (int)strlen(strs[i]));
        strcat(encoded, buffer);
        strcat(encoded, strs[i]);
    }

    return encoded;
}

// Function to decode the encoded string back to a list of strings
char** decode(char* s, int* returnSize) {
    char** decoded = (char**)malloc(MAX_SIZE * sizeof(char*));
    int index = 0;
    int i = 0;
    *returnSize = 0;

    while (s[i] != '\0') {
        // Find the position of the delimiter '#'
        int len = 0;
        while (s[i] != '#') {
            len = len * 10 + (s[i] - '0');
            i++;
        }
        i++; // Skip the delimiter

        decoded[index] = (char*)malloc((len + 1) * sizeof(char));
        strncpy(decoded[index], &s[i], len);
        decoded[index][len] = '\0';
        index++;
        i += len;
    }

    *returnSize = index;
    return decoded;
}

int main() {
    char* strs[] = {"neet", "code", "love", "you"};
    int strsSize = 4;

    // Encode the list of strings
    char* encoded = encode(strs, strsSize);
    printf("Encoded: %s\n", encoded);

    // Decode the encoded string back to the list of strings
    int returnSize;
    char** decoded = decode(encoded, &returnSize);

    printf("Decoded: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", decoded[i]);
        free(decoded[i]); // Free the individual strings
    }
    printf("\n");

    // Free the allocated memory
    free(encoded);
    free(decoded);

    return 0;
}
