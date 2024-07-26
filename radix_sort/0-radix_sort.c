#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Finds the maximum number in an array.
 * @array: The array to search.
 * @size: The size of the array.
 *
 * Return: The maximum number in the array.
 */
int get_max(int *array, size_t size)
{
		int max = array[0];
		size_t i;

		for (i = 1; i < size; i++)
		{
				if (array[i] > max)
						max = array[i];
		}
		return (max);
}

/**
 * count_sort - Performs counting sort on the array based on the digit
 * represented by exp.
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The exponent representing the digit to sort by.
 */
void count_sort(int *array, size_t size, int exp)
{
		int *output = malloc(size * sizeof(int));
		int count[10] = {0};
		size_t i;

		if (!output)
				return;

		for (i = 0; i < size; i++)
				count[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
				count[i] += count[i - 1];

		for (i = size; i > 0; i--)
		{
				output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
				count[(array[i - 1] / exp) % 10]--;
		}

		for (i = 0; i < size; i++)
				array[i] = output[i];

		free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
		int max, exp;

		if (!array || size < 2)
				return;

		max = get_max(array, size);

		for (exp = 1; max / exp > 0; exp *= 10)
		{
				count_sort(array, size, exp);
				print_array(array, size);
		}
}
