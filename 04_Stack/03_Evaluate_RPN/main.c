#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 1000

typedef struct {
    int top;
    int data[MAX_STACK_SIZE];
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->data[++(s->top)] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int evalRPN(char **tokens, int tokensSize) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < tokensSize; i++) {
        if (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0 || strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0) {
            int b = pop(&stack);
            int a = pop(&stack);
            if (strcmp(tokens[i], "+") == 0) push(&stack, a + b);
            if (strcmp(tokens[i], "-") == 0) push(&stack, a - b);
            if (strcmp(tokens[i], "*") == 0) push(&stack, a * b);
            if (strcmp(tokens[i], "/") == 0) push(&stack, a / b);
        } else {
            push(&stack, atoi(tokens[i]));
        }
    }

    return pop(&stack);
}

int main() {
    // Example usage
    char *tokens[] = {"1", "2", "+", "3", "*", "4", "-"};
    int tokensSize = sizeof(tokens) / sizeof(tokens[0]);

    int result = evalRPN(tokens, tokensSize);
    printf("Result: %d\n", result);  // Output: 5

    return 0;
}
