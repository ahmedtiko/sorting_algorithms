#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 * @head: Pointer to a pointer to the head of the list
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **head)
{
	if (node1 == NULL || node2 == NULL || head == NULL || *head == NULL)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*head = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm
 * @list: A pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next, list);
				swapped = 1;
				print_list(*list);
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current, list);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}
