#include "sort.h"

/**
 * swap_with_prev - swap node with prev node
 * @ptr: node to swap
 */

void swap_with_prev(listint_t **ptr)
{
	listint_t *node_prev, *the_next;

	node_prev = (*ptr)->prev;
	the_next = (*ptr)->next;

	if (the_next != NULL)
		the_next->prev = node_prev;
	if (node_prev->prev != NULL)
		node_prev->prev->next = (*ptr);

	(*ptr)->next = node_prev;
	(*ptr)->prev = node_prev->prev;

	node_prev->next = the_next;
	node_prev->prev = (*ptr);

}
/**
 * cocktail_sort_list - sort list using cocktail algo
 *
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int deb = 0, fin = 0, i;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;
	/* compte le nombre de valeur dans la liste */
	current = *list;
	while ((current = current->next) != NULL)
		fin++;

	current = *list;
	while (deb < fin)
	{
		for (i = deb++; i < fin; i++)
		{
			if (current->n > current->next->n)
			{
				current = current->next;
				swap_with_prev(&current);
				print_list(*list);
			}
			current = current->next;
		}

		current = current->prev;
		for (i = fin; i > deb; i--)
		{
			if (current->n < current->prev->n)
			{
				swap_with_prev(&current);
				if (current->prev == NULL) /* si current = head */
					*list = current;
				print_list(*list);
			}
		else
			current = current->prev;
		}
	}
}
