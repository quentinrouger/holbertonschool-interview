#!/usr/bin/python3

def rain(walls):
    """
    Calculate the amount of water retained between walls after rain.

    Args:
        walls (list of int): List of non-negative integers representing the heights of walls.

    Returns:
        int: Total amount of rainwater retained.

    Assumptions:
        - The ends of the list (before index 0 and after index walls[-1]) are not walls,
          meaning they will not retain water.
        - If the list is empty, return 0.
    """
    if not walls:
        return 0
    
    # Initialize variables to store maximum heights from left and right
    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n
    water = 0
    
    # Calculate maximum heights of walls from left side
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])
    
    # Calculate maximum heights of walls from right side
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])
    
    # Calculate amount of water retained for each wall
    for i in range(n):
        water += max(0, min(left_max[i], right_max[i]) - walls[i])
    
    return water

# Test cases
if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))  # Output: 6
    
    walls = [2, 0, 0, 4, 0, 0, 1, 0]
    print(rain(walls))  # Output: 6
