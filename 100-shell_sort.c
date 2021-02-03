#include "sort.h"
/**
 * shell_sort - Shell Sort Algorithm
 * @array: Array to be sorted
 * @size: Size of the Array
 * Return: Void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	unsigned int i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i += 1)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
