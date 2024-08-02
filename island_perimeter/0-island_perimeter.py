#!/usr/bin/python3
"""
Create a function def island_perimeter(grid): that returns
the perimeter of the island described in grid
"""

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in grid.

    :param grid: List[List[int]] - 2D list representing the island and water
    :return: int - perimeter of the island
    """
    if not grid or not grid[0]:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                # Check top
                if r == 0 or grid[r-1][c] == 0:
                    perimeter += 1
                # Check bottom
                if r == rows-1 or grid[r+1][c] == 0:
                    perimeter += 1
                # Check left
                if c == 0 or grid[r][c-1] == 0:
                    perimeter += 1
                # Check right
                if c == cols-1 or grid[r][c+1] == 0:
                    perimeter += 1

    return perimeter
