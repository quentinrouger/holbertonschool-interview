#include "slide_line.h"
#include <stddef.h>

/**
 * slide_line - Slides and merges an array of integers
 *              towards a given direction
 * @line: Array of integers containing size elements
 * @size: Number of elements in @line
 * @direction: Direction to slide the elements
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, j;
	int merged = 0;

	if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; ++i)
		{
			if (line[i] == 0)
				continue;
			for (j = i + 1; j < size; ++j)
			{
				if (line[j] != 0)
				{
					if (line[i] == line[j] && !merged)
					{
						line[i] *= 2;
						line[j] = 0;
						merged = 1;
					}
					break;
				}
			}
			merged = 0;
		}
		for (i = 0, j = 0; i < size; ++i)
		{
			if (line[i] != 0)
			{
				if (i != j)
				{
					line[j] = line[i];
					line[i] = 0;
				}
				++j;
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (i = size; i > 0; --i)
		{
			if (line[i - 1] == 0)
				continue;
			for (j = i - 1; j > 0; --j)
			{
				if (line[j - 1] != 0)
				{
					if (line[i - 1] == line[j - 1] && !merged)
					{
						line[i - 1] *= 2;
						line[j - 1] = 0;
						merged = 1;
					}
					break;
				}
			}
			merged = 0;
		}
		for (i = size, j = size; i > 0; --i)
		{
			if (line[i - 1] != 0)
			{
				if (i != j)
				{
					line[j - 1] = line[i - 1];
					line[i - 1] = 0;
				}
				--j;
			}
		}
	}
	return (1);
}