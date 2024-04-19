#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express;

	if (!list)
		return (NULL);

	express = list->express;
	printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
	while (express && express->n < value)
	{
		list = express;
		express = express->express;
		if (express)
			printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
	}
	if (!express)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
		list->index, list->next->next->index);
		while (list->next && list->next->n < value)
		{
			printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
			list = list->next;
		}
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
	}
	else
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
		list->index, express->index);
		while (list && list->n < value)
		{
			printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
			list = list->next;
		}
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
	}
	if (list && list->n == value)
		return (list);

	return (NULL);
}
