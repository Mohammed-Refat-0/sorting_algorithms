#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly lonked-list of integers
 * in ascending order
 * using using Insertion sort algorithm
 * @list: doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *ptr;
    listint_t *temp;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	ptr = (*list);
	temp = (*list)->next;

	while (temp != NULL)
	{
		ptr = temp;
		temp = temp->next;
		while (ptr != NULL && ptr->prev != NULL)
		{
			if (ptr->prev->n > ptr->n)
			{
				if ((ptr->prev)->prev)
                {
					(ptr->prev)->prev->next = (ptr);
                }
				if ((ptr)->next)
				{
					(ptr)->next->prev = (ptr->prev);
				}
				(ptr->prev)->next = (ptr)->next;
				(ptr)->prev = (ptr->prev)->prev;
				(ptr->prev)->prev = (ptr);
				(ptr->next) = (ptr->prev);

				if (!ptr->prev)
				{
					*list = ptr;
				}
				print_list((const listint_t *)*list);
			}
			ptr = ptr->prev;
		}
	}
}
