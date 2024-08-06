#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sort the string
void sortString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// Structure for storing groups of anagrams
typedef struct {
    char **anagrams;
    int count;
    int capacity;
} AnagramGroup;

AnagramGroup* createAnagramGroup(int capacity) {
    AnagramGroup *group = (AnagramGroup*) malloc(sizeof(AnagramGroup));
    group->anagrams = (char**) malloc(capacity * sizeof(char*));
    group->count = 0;
    group->capacity = capacity;
    return group;
}

void addAnagram(AnagramGroup *group, char *anagram) {
    if (group->count == group->capacity) {
        group->capacity *= 2;
        group->anagrams = (char**) realloc(group->anagrams, group->capacity * sizeof(char*));
    }
    group->anagrams[group->count++] = anagram;
}

void freeAnagramGroup(AnagramGroup *group) {
    free(group->anagrams);
    free(group);
}

// Structure for storing all groups
typedef struct {
    AnagramGroup **groups;
    int count;
    int capacity;
} AnagramGroups;

AnagramGroups* createAnagramGroups(int capacity) {
    AnagramGroups *groups = (AnagramGroups*) malloc(sizeof(AnagramGroups));
    groups->groups = (AnagramGroup**) malloc(capacity * sizeof(AnagramGroup*));
    groups->count = 0;
    groups->capacity = capacity;
    return groups;
}

void addAnagramGroup(AnagramGroups *groups, AnagramGroup *group) {
    if (groups->count == groups->capacity) {
        groups->capacity *= 2;
        groups->groups = (AnagramGroup**) realloc(groups->groups, groups->capacity * sizeof(AnagramGroup*));
    }
    groups->groups[groups->count++] = group;
}

void freeAnagramGroups(AnagramGroups *groups) {
    for (int i = 0; i < groups->count; i++) {
        freeAnagramGroup(groups->groups[i]);
    }
    free(groups->groups);
    free(groups);
}

int main() {
    char *strs[] = {"act", "pots", "tops", "cat", "stop", "hat"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);

    AnagramGroups *anagramGroups = createAnagramGroups(10);

    for (int i = 0; i < strsSize; i++) {
        char *sortedStr = strdup(strs[i]);
        sortString(sortedStr);

        int found = 0;
        for (int j = 0; j < anagramGroups->count; j++) {
            if (strcmp(anagramGroups->groups[j]->anagrams[0], sortedStr) == 0) {
                addAnagram(anagramGroups->groups[j], strs[i]);
                found = 1;
                break;
            }
        }

        if (!found) {
            AnagramGroup *newGroup = createAnagramGroup(10);
            addAnagram(newGroup, strs[i]);
            addAnagram(newGroup, sortedStr);
            addAnagramGroup(anagramGroups, newGroup);
        }
    }

    printf("Grouped Anagrams:\n");
    for (int i = 0; i < anagramGroups->count; i++) {
        for (int j = 1; j < anagramGroups->groups[i]->count; j++) {
            printf("%s ", anagramGroups->groups[i]->anagrams[j]);
        }
        printf("\n");
    }

    freeAnagramGroups(anagramGroups);

    return 0;
}
