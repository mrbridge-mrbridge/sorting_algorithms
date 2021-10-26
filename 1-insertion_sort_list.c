#include "sort.h"

/**
 * insertion_sort_list - sorts a list using the insertion
 * sort algorithm
 * @list: pointer to pointer of the list to be sorted
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *swaper;
	listint_t *swapnext;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	swaper = (*list)->next;

	while (swaper != NULL)
	{
		swapnext = swaper->next;
		while (swaper->prev != NULL && swaper->prev->n > swaper->n)
		{
			swaper->prev->next = swaper->next;
			if (swaper->next != NULL)
				swaper->next->prev = swaper->prev;
			swaper->next = swaper->prev;
			swaper->prev = swaper->next->prev;
			swaper->next->prev = swaper;
			if (swaper->prev == NULL)
				*list = swaper;
			else
				swaper->prev->next = swaper;
			print_list(*list);
		}
		swaper = swapnext;
	}

}
