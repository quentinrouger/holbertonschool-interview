#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays of array.
 * @array: The array to be sorted.
 * @left: The left subarray.
 * @left_size: The size of the left subarray.
 * @right: The right subarray.
 * @right_size: The size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
		size_t i = 0, j = 0, k = 0;

		printf("Merging...\n");
		printf("[left]: ");
		print_array(left, left_size);
		printf("[right]: ");
		print_array(right, right_size);

		while (i < left_size && j < right_size)
		{
				if (left[i] <= right[j])
				{
						array[k] = left[i];
						i++;
				}
				else
				{
						array[k] = right[j];
						j++;
				}
				k++;
		}
		while (i < left_size)
		{
				array[k] = left[i];
				i++;
				k++;
		}
		while (j < right_size)
		{
				array[k] = right[j];
				j++;
				k++;
		}

		printf("[Done]: ");
		print_array(array, left_size + right_size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
		if (size < 2)
				return;

		size_t mid = size / 2;
		int *left = malloc(mid * sizeof(int));
		int *right = malloc((size - mid) * sizeof(int));

		for (size_t i = 0; i < mid; i++)
				left[i] = array[i];
		for (size_t i = mid; i < size; i++)
				right[i - mid] = array[i];

		merge_sort(left, mid);
		merge_sort(right, size - mid);
		merge(array, left, mid, right, size - mid);

		free(left);
		free(right);
}
