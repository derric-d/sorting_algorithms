#include "sort.h"


/**
 * swap_node - swap nodes on a linked list
 * @n1 : num 1
 * @n2: num 2
 */
void swap_node(listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;
	if (n2->next)
		n2->next->prev = n1;
	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;
}
/**
 * inssertion_sort_list - insertion sort implementation for linked lists
 * @list: list passed
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL;
	listint_t *i = NULL;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;

	while (curr)
	{
		i = curr;
		curr = curr->next;
		while (i && i->prev)
		{
			if (i->prev->n > i->n)
			{
				swap_node(i->prev, i);
				if (!i->prev)
					*list = i;
				print_list(*list);
			}
			else
				i = i->prev;
		}
	}
}
