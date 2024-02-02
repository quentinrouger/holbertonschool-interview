#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid(int grid[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * is_stable - Check if a sandpile is stable
 * @grid: 3x3 grid
 * Return: 1 if stable, 0 otherwise
 */
int is_stable(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                return 0;
            }
        }
    }
    return 1;
}

/**
 * topple - Perform a toppling round on a sandpile
 * @grid: 3x3 grid
 */
void topple(int grid[3][3]) {
    int next[3][3] = {{0}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] >= 4) {
                next[i][j] -= 4;
                if (i > 0) next[i - 1][j]++;
                if (i < 2) next[i + 1][j]++;
                if (j > 0) next[i][j - 1]++;
                if (j < 2) next[i][j + 1]++;
            }
            next[i][j] += grid[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = next[i][j];
        }
    }
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    while (!is_stable(grid1)) {
        printf("=\n");
        print_grid(grid1);
        topple(grid1);
    }
}
