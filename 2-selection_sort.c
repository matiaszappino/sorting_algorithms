#include "sort.h"
/**
 * selection_sort - Selection Sort Algorithm
 * @array: Array to be sorted
 * @size: Size of the Array
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		unsigned int min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
