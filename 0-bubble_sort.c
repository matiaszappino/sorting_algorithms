#include "sort.h"
/**
 * bubble_sort - Bubble Sort method to sort an array of int
 * @array: Arrray to be sorted
 * @size: Size of the array
 * Return: Return void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, c, k;
	int x, counter = 1;

	if (array == NULL || size < 2)
		return;

	for (k = 0; k < size - 1; k++)
	{
		for (i = 0; i < size - counter; i++)
		{
			if (array[i] > array[i + 1])
			{
				x = array[i];
				array[i] = array[i + 1];
				array[i + 1] = x;
				for (c = 0; c < size; c++)
				{
					printf("%i", array[c]);
					if (c != size - 1)
					{
						printf(", ");
					}
				}
				putchar('\n');
			}
		}
		counter += 1;
	}
}
