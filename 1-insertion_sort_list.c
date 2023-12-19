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

    if (!list || !*list)
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
            listint_t *prevn = ptr->prev;
            listint_t *nextn = ptr->next;

            if (prevn->prev)
			{
				prevn->prev->next = ptr;
			}
            if (nextn)
			{
				nextn->prev = prevn;
			}

            ptr->prev = prevn->prev;
            prevn->next = nextn;
            prevn->prev = ptr;
            ptr->next = prevn;

            if (!ptr->prev)
			{
				*list = ptr;
			}

            print_list((const listint_t *)*list);
        }
        ptr = ptr->prev;
    }
}
