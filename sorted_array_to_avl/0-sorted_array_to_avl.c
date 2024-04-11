#include "binary_trees.h"
#include <stdlib.h>

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (size == 0)
        return (NULL);

    return sorted_array_to_avl_recursive(array, 0, size - 1);
}

/**
 * sorted_array_to_avl_recursive - Recursive helper function to build AVL tree
 * @array: Pointer to the first element of the array
 * @start: Index of the start of the subarray
 * @end: Index of the end of the subarray
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_recursive(int *array, int start, int end)
{
    int mid;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;
    avl_t *root = malloc(sizeof(avl_t));
    if (!root)
        return (NULL);

    root->n = array[mid];
    root->left = sorted_array_to_avl_recursive(array, start, mid - 1);
    root->right = sorted_array_to_avl_recursive(array, mid + 1, end);
    root->parent = NULL;

    if (root->left)
        root->left->parent = root;
    if (root->right)
        root->right->parent = root;

    return (root);
}
