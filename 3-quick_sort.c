#include "sort.h"
/**
 * selection_sort - Selection Sort Algorithm
 * @array: Array to be sorted
 * @size: Size of the Array
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
		return;
    quicksort(array, 0, size - 1, size);
}
/**
 * selection_sort - Selection Sort Algorithm
 * @array: Array to be sorted
 * @size: Size of the Array
 * Return: Void
 */
void quicksort(int *array, ssize_t startindex, ssize_t endindex, size_t size)
{
    int pivot_index;
    
    if (startindex < endindex)
    {
        pivot_index = partition(array, startindex, endindex, size);

        quicksort(array, startindex, pivot_index - 1, size);

        quicksort(array, pivot_index + 1, endindex, size);
    }
}
/**
 * selection_sort - Selection Sort Algorithm
 * @array: Array to be sorted
 * @size: Size of the Array
 * Return: Void
 */
int partition(int *array, ssize_t startindex, ssize_t endindex, size_t size)
{
    int temp;
    ssize_t i;
    int pivot_value = array[endindex];
    int partition_index = startindex;

    for (i = startindex; i < endindex; i++)
    {
        if(array[i] <= pivot_value)
        {
            if (partition_index != i)
			{
                temp = array[i];
                array[i] = array[partition_index];
                array[partition_index] = temp;
                print_array(array, size);
            }
            partition_index++;
        }
    }
    if (endindex != partition_index && array[endindex] != array[partition_index])
    {
        temp = array[endindex];
        array[endindex] = array[partition_index];
        array[partition_index] = temp;
        print_array(array, size);
    }
    return (partition_index);
}