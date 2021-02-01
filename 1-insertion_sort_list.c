#include "sort.h"
/**
 * insertion_sort_list - Bubble Sort method to sort an array of int
 * @list: Arrray to be sorted
 * Return: Return void
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *tmp = *list;

    if (*list == NULL || (*list)->next == NULL)
        return;

    while (tmp != NULL)
    {
        listint_t *next = tmp->next;
        listint_t *start = *list;
        listint_t *prev = *list;
        while (start != next)
        {
            if (start->n > tmp->n)
            {
                tmp->next = start;
                if (start == *list)
                {
                    *list = tmp;
                }
                else
                {
                    prev->next = tmp;
                }
                while (start->next != tmp)
                {
                    start = start->next;
                }
                start->next = next;
            }
            prev = start;
            start = start->next;
        }
        tmp = next;
    }
}
