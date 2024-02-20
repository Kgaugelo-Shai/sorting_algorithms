#include "sort.h"
#include <stdbool.h>
/**
 * swap_upper_node - swaps a node in with upper node in a doubly lined list
 * @list: pointer to the head of a doubly linked list
 * @tail: pointer to tail of doubly linked list
 * @index: pointer to the current node
 */
void swap_upper_node(listint_t **list, listint_t **tail, listint_t **index)
{
	listint_t *temp = (*index)->next;

	if ((*index)->prev != NULL)
		(*index)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*index)->prev;
	(*index)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *index;
	else
		*tail = *index;
	(*index)->prev = temp;
	temp->next = *index;
	*index = temp;
}
/**
 * swap_lower_node - swaps a node in with lower node in a doubly lined list
 * @list: pointer to the head of a doubly linked list
 * @tail: pointer to tail of doubly linked list
 * @index: pointer to the current node
 */
void swap_lower_node(listint_t **list, listint_t **tail, listint_t **index)
{
	listint_t *temp = (*index)->prev;

	if ((*index)->next != NULL)
		(*index)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*index)->next;
	(*index)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *index;
	else
		*list = *index;
	(*index)->next = temp;
	temp->prev = *index;
	*index = temp;
}
/**
 * cocktail_sort_list - sorts a doubly linked list
 * using the Cocktail shaker sort algorithm.
 * @list: The doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *index, *tail;
	bool is_swapped = true;

	if (*list == NULL || (*list)->next == NULL || list == NULL)
		return;

	tail = *list;
	while (tail->next != NULL)
		tail = tail->next;

	while (is_swapped == true)
	{
		is_swapped = false;
		for (index = *list; index != tail; index = index->next)
		{
			if (index->n > index->next->n)
			{
				swap_upper_node(list, &tail, &index);
				print_list(*list);
				is_swapped = true;
			}
		}
		for (index = index->prev; index != *list; index = index->prev)
		{
			if (index->n < index->prev->n)
			{
				swap_lower_node(list, &tail, &index);
				print_list(*list);
				is_swapped = true;
			}
		}
	}
}
