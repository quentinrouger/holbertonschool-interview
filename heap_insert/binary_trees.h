#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s heap_t;
typedef struct binary_tree_s binary_tree_t;

void binary_tree_print(const binary_tree_t *tree);

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
heap_t *swap_value(heap_t *parent, heap_t *child);
int get_size(heap_t *tree);
heap_t *get_parent(heap_t *tree, int size, int index);

#endif /* _BINARY_TREES_H_ */
