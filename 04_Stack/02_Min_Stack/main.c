#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *data;
    int *minData;
    int top;
    int minTop;
    int capacity;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int capacity) {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->minData = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->minTop = -1;
    stack->capacity = capacity;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top < obj->capacity - 1) {
        obj->data[++obj->top] = val;
        if (obj->minTop == -1 || val <= obj->minData[obj->minTop]) {
            obj->minData[++obj->minTop] = val;
        }
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        if (obj->data[obj->top] == obj->minData[obj->minTop]) {
            obj->minTop--;
        }
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->top >= 0) {
        return obj->data[obj->top];
    }
    return -1; // Or some other error value
}

int minStackGetMin(MinStack* obj) {
    if (obj->minTop >= 0) {
        return obj->minData[obj->minTop];
    }
    return INT_MAX; // Or some other error value
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->minData);
    free(obj);
}

// Example usage
int main() {
    MinStack* minStack = minStackCreate(100);
    minStackPush(minStack, 1);
    minStackPush(minStack, 2);
    minStackPush(minStack, 0);
    
    printf("getMin: %d\n", minStackGetMin(minStack)); // return 0
    minStackPop(minStack);
    printf("top: %d\n", minStackTop(minStack));       // return 2
    printf("getMin: %d\n", minStackGetMin(minStack)); // return 1
    
    minStackFree(minStack);
    return 0;
}
