#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int heapSize;
    int k;
} KthLargest;

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with node i
void heapify(int *heap, int heapSize, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;

    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, heapSize, smallest);
    }
}

// Function to insert a new element into the heap
void insertHeap(KthLargest *obj, int val) {
    if (obj->heapSize < obj->k) {
        obj->heap[obj->heapSize++] = val;
        for (int i = obj->heapSize / 2 - 1; i >= 0; i--)
            heapify(obj->heap, obj->heapSize, i);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapify(obj->heap, obj->heapSize, 0);
    }
}

// Function to create the KthLargest object
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->heapSize = 0;
    obj->k = k;

    for (int i = 0; i < numsSize; i++)
        insertHeap(obj, nums[i]);

    return obj;
}

// Function to add a value to the stream
int kthLargestAdd(KthLargest* obj, int val) {
    insertHeap(obj, val);
    return obj->heap[0];
}

// Function to free memory
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

int main() {
    int nums[] = {1, 2, 3, 3};
    int k = 3;
    KthLargest* kthLargest = kthLargestCreate(k, nums, 4);

    printf("After adding 3: %d\n", kthLargestAdd(kthLargest, 3)); // Output: 3
    printf("After adding 5: %d\n", kthLargestAdd(kthLargest, 5)); // Output: 3
    printf("After adding 6: %d\n", kthLargestAdd(kthLargest, 6)); // Output: 3
    printf("After adding 7: %d\n", kthLargestAdd(kthLargest, 7)); // Output: 5
    printf("After adding 8: %d\n", kthLargestAdd(kthLargest, 8)); // Output: 6

    kthLargestFree(kthLargest);
    return 0;
}
