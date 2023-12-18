#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly lonked-list of integers
 * in ascending order
 * using using Insertion sort algorithm
 * @list: doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	listint_t *ptr = (*list);

	listint_t *(temp) = (*list)->next;

	while (temp != NULL)
	{
		ptr = temp;
		temp = temp->next;
		while (temp != NULL && temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				if (ptr->prev->prev)
					ptr->prev->prev->next = ptr;
				if (ptr->next)
				{
					ptr->next->prev = ptr->prev;
				}
				ptr->prev->next = ptr->next;
				ptr->prev = ptr->prev->prev;
				ptr->prev->prev = ptr;
				ptr->next = ptr->prev;

				if (!temp->prev)
				{
					*list = temp;
				}
				print_list((const listint_t *)*list);
			}
			else
			{
				ptr->prev;
			}
		}
		ptr->next;
	}
}
