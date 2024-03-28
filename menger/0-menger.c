#include "menger.h"

/**
 * drawCell - Draw a single cell of the Menger Sponge
 * @x: The x coordinate of the cell
 * @y: The y coordinate of the cell
 * @size: The size of the cell
 *
 * Draws a single cell of the Menger Sponge at the specified coordinates
 * with the specified size.
 * The cell is drawn as ' ' if it is part of the empty space, or '#' otherwise.
 */
void drawCell(int x, int y, int size)
{
	while (size)
	{
		if (x % 3 == 1 && y % 3 == 1)
		{
			printf(" ");
			return;
		}
		x /= 3;
		y /= 3;
		size /= 3;
	}
	printf("#");
}

/**
 * menger - Draw a 2D Menger Sponge
 * @level: The level of the Menger Sponge to draw
 *
 * Draws a 2D Menger Sponge with the specified level.
 * If the level is lower than 0, the function does nothing.
 * The function calculates the size of the sponge and calls drawCell
 * to draw each cell of the sponge.
 */
void menger(int level)
{
	int size, x, y;

	if (level < 0)
		return;

	size = pow(3, level);
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			drawCell(x, y, size);
		}
		printf("\n");
	}
}
