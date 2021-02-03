#include "sort.h"

/**
 * insertion_sort_list - order a double linked
 * list using the algorithm insertion_sort
 * @list: Double linked list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *aux = NULL, *temp = NULL, *temp2 = NULL;

	if (!list || !(*list) || (!(*list)->next))
		return;

	aux = *list;

	while (aux)
	{
		if (aux->prev)
		{
			if (aux->prev->n > aux->n)
			{
				temp = aux;
				temp2 = aux;
				swap_nodes(list, aux->prev, aux);
				aux = aux->next;
				print_list(*list);
				while (temp2)
				{
					if (temp2->n > temp->n)
					{
						swap_nodes(list, temp2, temp);
						print_list(*list);
					}
					temp2 = temp2->prev;
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

void swap_nodes(listint_t **list, listint_t *node_A, listint_t *node_B)
{
	listint_t *t1 = node_A->prev;
	listint_t *t2 = node_B->next;

	if (node_A->prev == NULL && node_B->next == NULL)
	{
		node_A->next = NULL;
		node_B->prev = NULL;
		node_A->prev = node_B;
		node_B->next = node_A;
		*list = node_B;
	}
	else if (node_A->prev == NULL)
	{
		node_A->next = t2;
		node_B->prev = NULL;
		node_A->prev = node_B;
		node_B->next = node_A;
		t2->prev = node_A;
		*list = node_B;
	}
	else if (node_B->next == NULL)
	{
		node_A->prev = node_B;
		node_B->next = node_A;
		node_B->prev = t1;
		t1->next = node_B;
		node_A->next = NULL;
	}
	else
	{
		node_A->prev = node_B;
		node_B->next = node_A;
		node_A->next = t2;
		node_B->prev = t1;
		t1->next = node_B;
		t2->prev = node_A;
	}
}