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
        while (ptr != NULL && ptr->prev != NULL && ptr->prev->n > ptr->n)
        {
            listint_t *prev_node = ptr->prev;
            listint_t *next_node = ptr->next;

            if (prev_node->prev)
			{
				prev_node->prev->next = ptr;
			}
            if (next_node)
			{
				next_node->prev = prev_node;
			}

            ptr->prev = prev_node->prev;
            prev_node->next = next_node;
            prev_node->prev = ptr;
            ptr->next = prev_node;

            if (!ptr->prev)
			{
				*list = ptr;
			}

            print_list((const listint_t *)*list);
        }
        ptr = ptr->prev;
    }
}
