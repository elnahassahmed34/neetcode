#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int seenNumbers[1000] = {0}; // Array to store seen numbers
    int index = 0;

    while (n != 1) {
        if (seenNumbers[n] == 1) {
            return false; // Loop detected
        }
        seenNumbers[n] = 1;
        n = sumOfSquares(n);
    }
    return true;
}

int main() {
    int test1 = 100;
    int test2 = 101;

    printf("Is %d a happy number? %s\n", test1, isHappy(test1) ? "True" : "False");
    printf("Is %d a happy number? %s\n", test2, isHappy(test2) ? "True" : "False");

    return 0;
}
