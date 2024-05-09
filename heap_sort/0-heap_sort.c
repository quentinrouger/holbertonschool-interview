#include "sort.h"

/**
 * heapify - Helper function to build a max heap
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @index: Index of the current node
 * @heap_size: Size of the heap
 */
void heapify(int *array, size_t size, int index, size_t heap_size);

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}

/**
 * heapify - Helper function to build a max heap
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @index: Index of the current node
 * @heap_size: Size of the heap
 */
void heapify(int *array, size_t size, int index, size_t heap_size)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < (int)heap_size && array[left] > array[largest])
		largest = left;

	if (right < (int)heap_size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		int temp = array[index];

		array[index] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, size, largest, heap_size);
	}
}
