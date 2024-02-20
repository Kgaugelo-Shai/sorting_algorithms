#include "sort.h"
/**
 * getSize - returns the size of the list
 * @list: list to analyze
 * Return: size of list as an integer
 */
int getSize(listint_t **list)
{
	int count = 0;
	listint_t *temp = *list;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

/**
 * insertion_sort_list - function to sort a doubly linked list of integers
 * using
 * the sort insertion algotithm
 * @list: pointer to the head of the list
 */

/*
 * get length of list and check if list is empty and check length of list
 * if list is not empty, traverse the list
 * if list is empty, return
 * if list has only one node, return
 * the outter loop must start from the second node
 * the inner loop must start from the first node and traverse the list in
 * reverse store the current node in a temp variable if the current node is
 * greater than the previous node, swap the nodes and decrease the count if the
 * current node is less than the previous node, store the temp variable in the
 * current node and increase the count
 */

void insertion_sort_list(listint_t **list)
{
	int length = getSize(list);
	listint_t *outter;

	if (list == NULL || length < 2 || *list == NULL || (*list)->next == NULL)
		return;

	outter = (*list)->next;

	while (outter != NULL)
	{
		listint_t *temp_key = outter;
		listint_t *inner = outter->prev;

		while (inner != NULL && inner->n > temp_key->n)
		{
			if (inner->prev != NULL)
			{
				inner->prev->next = temp_key;
			}
			else
			{
				*list = temp_key;
			}
			temp_key->prev = inner->prev;
			inner->prev = temp_key;
			inner->next = temp_key->next;

			if (temp_key->next != NULL)
			{
				temp_key->next->prev = inner;
			}
			temp_key->next = inner;
			print_list(*list);
			inner = temp_key->prev;
		}
		outter = outter->next;
	}
}
