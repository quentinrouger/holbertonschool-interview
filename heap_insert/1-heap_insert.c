#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *newNode;
	int size;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	size = get_size(*root);
	parent = get_parent(*root, (size - 1) / 2, 0);
	newNode = binary_tree_node(parent, value);
	if (!newNode)
		return (NULL);
	if (!parent->left)
		parent->left = newNode;
	else
		parent->right = newNode;
	while (newNode->parent && newNode->n > parent->n)
	{
		newNode = swap_value(parent, newNode);
		parent = parent->parent;
	}
	return (newNode);
}

/**
 * swap_value - swap the value between two nodes
 * @parent: the first node to swap
 * @child: the second node to swap
 * Return: pointer to the new place of the node followed
 */
heap_t *swap_value(heap_t *parent, heap_t *child)
{
	int temp = child->n;

	child->n = parent->n;
	parent->n = temp;
	return (parent);
}

/**
 * get_size - find the size of the tree
 * @tree: the tree
 * Return: size of the tree
 **/
int get_size(heap_t *tree)
{
	if (!tree)
		return (0);
	return (get_size(tree->left) + get_size(tree->right) + 1);
}

/**
 * get_parent - get the parent node
 * @tree: tree to check
 * @size: size of the tree
 * @index: index of the parent node
 * Return: pointer to the parent node
 */
heap_t *get_parent(heap_t *tree, int size, int index)
{
	heap_t *left, *right;

	if (index == size)
		return (tree);
	if (index > size)
		return (NULL);

	left = get_parent(tree->left, size, 2 * index + 1);
	right = get_parent(tree->right, size, 2 * index + 2);

	if (left)
		return (left);
	return (right);
}
