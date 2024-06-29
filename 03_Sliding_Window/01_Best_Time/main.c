#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}

int main() {
    int prices1[] = {10, 1, 5, 6, 7, 1};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("Max Profit: %d\n", maxProfit(prices1, size1)); // Output: 6

    int prices2[] = {10, 8, 7, 5, 2};
    int size2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("Max Profit: %d\n", maxProfit(prices2, size2)); // Output: 0

    return 0;
}
