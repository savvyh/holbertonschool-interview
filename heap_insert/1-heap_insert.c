#include <stdlib.h>
#include "binary_trees.h"

/**
 * swap_nodes - Swap the values of two heap nodes
 * @a: First node
 * @b: Second node
 */
static void swap_nodes(heap_t *a, heap_t *b)
{
	int tmp;

	tmp = a->n;
	a->n = b->n;
	b->n = tmp;
}

/**
 * heapify_up - Restore max heap property going up
 * @node: Node to heapify
 *
 * Return: Final position of the node
 */
static heap_t *heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_nodes(node, node->parent);
		node = node->parent;
	}

	return (node);
}

/**
 * find_insert_position - Find next available position in heap (BFS)
 * @root: Pointer to root of heap
 *
 * Return: Parent node where insertion should occur
 */
static heap_t *find_insert_position(heap_t *root)
{
	heap_t **queue;
	heap_t *tmp;
	int front = 0;
	int back = 0;
	int size = 1024;

	queue = malloc(sizeof(heap_t *) * size);
	if (!queue)
		return (NULL);

	queue[back++] = root;

	while (front < back)
	{
		tmp = queue[front++];

		if (!tmp->left || !tmp->right)
		{
			free(queue);
			return (tmp);
		}

		queue[back++] = tmp->left;
		queue[back++] = tmp->right;
	}

	free(queue);
	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to root node
 * @value: Value to insert
 *
 * Return: Pointer to inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	heap_t *parent;

	if (!root)
		return (NULL);

	node = binary_tree_node(NULL, value);
	if (!node)
		return (NULL);

	if (*root == NULL)
	{
		*root = node;
		return (node);
	}

	parent = find_insert_position(*root);
	if (!parent)
		return (NULL);

	node->parent = parent;

	if (!parent->left)
		parent->left = node;
	else
		parent->right = node;

	return (heapify_up(node));
}