def max_profit(prices):
    if not prices:
        return 0

    min_price = prices[0]  # Initialize the minimum price with the first day's price.
    max_profit = 0  # Initialize the maximum profit to 0.

    for price in prices[1:]:
        # Update the minimum price encountered so far.
        if price < min_price:
            min_price = price
        else:
            # Calculate potential profit for the current price.
            profit = price - min_price
            # Update the maximum profit if the current profit is greater.
            if profit > max_profit:
                max_profit = profit

    return max_profit

# Example usage:
prices1 = [10, 1, 5, 6, 7, 1]
print("Max Profit:", max_profit(prices1))  # Output: 6

prices2 = [10, 8, 7, 5, 2]
print("Max Profit:", max_profit(prices2))  # Output: 0
