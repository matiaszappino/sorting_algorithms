#include "sort.h"
/**
 * insertion_sort_list - order a double linked
 * list using the algorithm insertion_sort
 * @list: Double linked list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *aux = NULL;
	listint_t *tmp = NULL;
	listint_t *tmp_two = NULL;

	if (!list || !(*list) || (!(*list)->next))
		return;

	aux = *list;

	while (aux)
	{
		if (aux->prev)
		{
			if (aux->prev->n > aux->n)
			{
				tmp = aux;
				tmp_two = aux;
				swap_nodes(list, aux->prev, aux);
				aux = aux->next;
				print_list(*list);
				while (tmp_two)
				{
					if (tmp_two->n > tmp->n)
					{
						swap_nodes(list, tmp_two, tmp);
						print_list(*list);
					}
					tmp_two = tmp_two->prev;
				}
			}
		}
		aux = aux->next;
	}
}

/**
 * swap_nodes - swap the nodes of the list
 * @list: Double linked list
 * @node_A: Node A
 * @node_B: Node B
 * Return: Nothing
 */

void swap_nodes(listint_t **list, listint_t *first_node, listint_t *second_node)
{
	listint_t *tmp = first_node->prev;
	listint_t *tmp_two = second_node->next;

	if (first_node->prev == NULL && second_node->next == NULL)
	{
		first_node->next = NULL;
		second_node->prev = NULL;
		first_node->prev = second_node;
		second_node->next = first_node;
		*list = second_node;
	}
	else if (first_node->prev == NULL)
	{
		first_node->next = tmp_two;
		second_node->prev = NULL;
		first_node->prev = second_node;
		second_node->next = first_node;
		tmp_two->prev = first_node;
		*list = second_node;
	}
	else if (second_node->next == NULL)
	{
		first_node->prev = second_node;
		second_node->next = first_node;
		second_node->prev = tmp;
		tmp->next = second_node;
		first_node->next = NULL;
	}
	else
	{
		first_node->prev = second_node;
		second_node->next = first_node;
		first_node->next = tmp_two;
		second_node->prev = tmp;
		tmp->next = second_node;
		tmp_two->prev = first_node;
	}
}