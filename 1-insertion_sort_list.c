#include "sort.h"

/**
 * swap_with_prev - swap node with prev node
 * @ptr: node to swap
 */
void swap_with_prev(listint_t **ptr)
{   listint_t *node_prev, *the_next;

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
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order
 * @list: List to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr;

	if (list == NULL || *list == NULL)
		return;

	ptr = (*list)->next;

	while (ptr != NULL)
	{
		while (ptr->prev != NULL && ptr->n < ptr->prev->n)
		{
			swap_with_prev(&ptr);

			if (ptr->prev == NULL) /* si ptr = head */
				*list = ptr;

			print_list(*list);
		}
		ptr = ptr->next;
	}
}
