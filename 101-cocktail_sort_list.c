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
 * cocktail_sort_list - double bubble listy trouble
 * @list: list passed
 *
 */
void cocktail_sort_list(listint_t **list)
{
	int f;
	listint_t *h;

	f = 1;
	if (!list || !*list)
		return;
	h = *list;
	while (1)
	{
		f = 0;
		for (; h->next;)/*forwards*/
		{
			if (h->next->n < h->n)
			{
				swap_node(h, h->next);
				if (!h->prev->prev)
					*list = h->prev;
				print_list(*list);
				f = 1;
			}
			else
				h = h->next;
		}
		for (; h->prev;)/*backwards*/
		{
			if (h->prev->n > h->n)
			{
				swap_node(h->prev, h);
				if (!h->prev)
					*list = h;
				print_list(*list);
				f = 1;
			}
			else
				h = h->prev;
		}
		if (f == 0)
			break;
	}
}
