#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>

/**
 * max - Returns the maximum of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: The maximum of a and b
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * is_bst_helper - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value for the current node
 * @max: Maximum value for the current node
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst_helper(tree->left, min, tree->n) &&
					is_bst_helper(tree->right, tree->n, max));
}

/**
 * is_balanced - Checks if a binary tree is balanced
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is balanced, 0 otherwise
 */
int is_balanced(const binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (1);
	lh = height(tree->left);
	rh = height(tree->right);
	if (abs(lh - rh) > 1)
		return (0);
	return (is_balanced(tree->left) && is_balanced(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX) && is_balanced(tree));
}
