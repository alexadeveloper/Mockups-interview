#include "binary_trees.h"
/**
 * checkFree - Check first position
 * @root: Pointer to the root
 * Return: Pointer to parent
 */
heap_t *checkFree(heap_t *root)
{
	heap_t *narr[1000];
	heap_t *strider = root;
	int inPos = 0, outPos = 0;

	while (strider && strider->left && strider->right)
	{
		narr[inPos] = strider->left;
		inPos += 1;
		if (inPos >= 999)
			inPos = 0;
		narr[inPos] = strider->right;
		inPos += 1;
		if (inPos >= 999)
			inPos = 0;
		strider = narr[outPos];
		outPos += 1;
		if (outPos >= 999)
			outPos = 0;
	}
	return (strider);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node
 * @value: is the value store in the node
 * Return: a pointer, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *posInser = NULL;
	heap_t *nuevo = NULL;
	int tmp;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	posInser = checkFree(*root);
	nuevo = binary_tree_node(posInser, value);
	if (posInser->left == NULL)
		posInser->left = nuevo;
	else
		posInser->right = nuevo;
	while (nuevo->parent && nuevo->n > (nuevo->parent)->n)
	{
		tmp = (nuevo->parent)->n;
		(nuevo->parent)->n = nuevo->n;
		nuevo->n = tmp;
		nuevo = nuevo->parent;
	}
	return (nuevo);
}