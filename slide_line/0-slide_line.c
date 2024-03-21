#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: array of integers
 * @size: size of the array
 * @direction: direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 if successful, 0 otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j, k;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; ++i)
        {
            if (line[i] == 0)
            {
                for (j = i + 1; j < size && line[j] == 0; ++j)
                    ;
                if (j == size)
                    break;
                line[i] = line[j];
                line[j] = 0;
            }
            for (k = i + 1; k < size; ++k)
            {
                if (line[k] != 0)
                {
                    if (line[i] == line[k])
                    {
                        line[i] += line[k];
                        line[k] = 0;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }
    else if (direction == SLIDE_RIGHT)
    {
        for (i = size - 1; i < size; --i)
        {
            if (line[i] == 0)
            {
                for (j = i - 1; j >= 0 && line[j] == 0; --j)
                    ;
                if (j == (size_t)-1)
                    break;
                line[i] = line[j];
                line[j] = 0;
            }
            for (k = i - 1; k >= 0; --k)
            {
                if (line[k] != 0)
                {
                    if (line[i] == line[k])
                    {
                        line[i] += line[k];
                        line[k] = 0;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }

    return (1);
}
