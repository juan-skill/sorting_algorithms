#include "sort.h"

/**
 * get_head - Get the head of a doubly linked list
 * @tmp: node in linked list
 * Return: head of linked list
 */
listint_t *get_head(listint_t *tmp)
{
	while (tmp->prev)
		tmp = tmp->prev;

	return (tmp);
}

/**
 * insertion_sort_list - Sort a doubly linked list of integers
 * in ascending order using insertion sort algorithm.
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *arrow_curr = *list, *hold = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	arrow_curr = arrow_curr->next;
	while (arrow_curr)
	{
		while (arrow_curr->prev != NULL &&
		       (arrow_curr->n < arrow_curr->prev->n))
		{
			hold = arrow_curr->prev;
			hold->next = arrow_curr->next;

			arrow_curr->prev = hold->prev;
			hold->prev = arrow_curr;
			arrow_curr->next = hold;


			if (hold->next)
				hold->next->prev = hold;
			if (arrow_curr->prev)
				arrow_curr->prev->next = arrow_curr;

			print_list(get_head(*list));
		}
		arrow_curr = arrow_curr->next;
	}

	*list = get_head(*list);
}
