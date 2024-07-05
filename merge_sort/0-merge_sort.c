#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays of array.
 * @array: The array to be sorted.
 * @temp: The temporary array used for merging.
 * @left: The starting index of the left subarray.
 * @mid: The ending index of the left subarray.
 * @right: The ending index of the right subarray.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid, k = left;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, mid - left);
    printf("[right]: ");
    print_array(array + mid, right - mid);

    while (i < mid && j < right)
    {
        if (array[i] <= array[j])
        {
            temp[k++] = array[i++];
        }
        else
        {
            temp[k++] = array[j++];
        }
    }
    while (i < mid)
    {
        temp[k++] = array[i++];
    }
    while (j < right)
    {
        temp[k++] = array[j++];
    }
    for (i = left; i < right; i++)
    {
        array[i] = temp[i];
    }

    printf("[Done]: ");
    print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursively sorts an array using merge sort algorithm.
 * @array: The array to be sorted.
 * @temp: The temporary array used for merging.
 * @left: The starting index of the subarray.
 * @right: The ending index of the subarray.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    if (right - left < 2)
        return;

    size_t mid = (left + right) / 2;

    merge_sort_recursive(array, temp, left, mid);
    merge_sort_recursive(array, temp, mid, right);
    merge(array, temp, left, mid, right);
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

    int *temp = malloc(size * sizeof(int));
    if (temp == NULL)
        return;

    merge_sort_recursive(array, temp, 0, size);
    free(temp);
}
