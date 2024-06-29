#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*)malloc(capacity * sizeof(char));
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, char ch) {
    stack->data[++stack->top] = ch;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    return stack->data[stack->top--];
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to validate the parentheses
bool isValid(char* s) {
    int length = strlen(s);
    Stack* stack = createStack(length);

    for (int i = 0; i < length; ++i) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(stack, ch);
        } else {
            if (isEmpty(stack)) {
                free(stack->data);
                free(stack);
                return false;
            }
            char top = pop(stack);
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                free(stack->data);
                free(stack);
                return false;
            }
        }
    }

    bool valid = isEmpty(stack);
    free(stack->data);
    free(stack);
    return valid;
}

int main() {
    char* s1 = "[]";
    printf("Input: %s, Output: %s\n", s1, isValid(s1) ? "true" : "false");

    char* s2 = "([{}])";
    printf("Input: %s, Output: %s\n", s2, isValid(s2) ? "true" : "false");

    char* s3 = "[(])";
    printf("Input: %s, Output: %s\n", s3, isValid(s3) ? "true" : "false");

    return 0;
}
