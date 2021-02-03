#include "sort.h"
/**
 * print_list - Prints a a doubly linked list
 * @list: A doubly linked list
 */
void print_list(const listint_t *list)
{
    int counter;

    counter = 0;
    while (list)
    {
        if (counter > 0)
            printf(", ");
        printf("%d", list->n);
        ++counter;
        list = list->next;
    }
    printf("\n");
}