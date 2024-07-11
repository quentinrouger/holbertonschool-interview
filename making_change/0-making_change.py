#!/usr/bin/python3
"""
Given a pile of coins of different values, determine the fewest number
of coins needed to meet a given amount total.
"""


def makeChange(coins, total):
    """
    Function to determine the fewest number of coins needed
    to meet a given amount total.
    """
    if total <= 0:
        return 0

    # Sort coins in descending order to try larger coins first
    coins.sort(reverse=True)

    # Create a list to store the minimum coins for each amount from 0 to total
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # Base case: no coins needed for total of 0

    # Iterate over each coin
    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    # If dp[total] is still infinity, means it's not possible to form the total
    return dp[total] if dp[total] != float('inf') else -1
