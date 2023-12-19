#include "sort.h"

/**
 * quick_sort_partition - helper function to partition, swap and print
 * array for the implmentation quick sort
 * @array: arry to sort
 * @lowerbound: lower limit to partition the array by
 * @upperbound: upper limit to partition the array by
 * @size: size of array
 * Return: int index of pivot
 */
int quick_sort_partition(int *array, int lowerbound, int upperbound,
		size_t size)
{
	int temp;
	int j;
	int i = lowerbound - 1;
	int pivot = array[upperbound];

	for (j = lowerbound; j <= upperbound; j++)
	{
		if (pivot >= array[j])
		{
			i++;
			if (j != i)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
	return (i);
}


/**
 * quick_sort_recurision-  recursive function to implment quick sort
 * @array: arry to sort
 * @lowerbound: lower limit to partition the array by
 * @upperbound: upper limit to partition the array by
 * @size: length of array
 */
void quick_sort_recurision(int *array, int lowerbound, int upperbound,
		size_t size)
{
	int index_pivot;

	if (upperbound > lowerbound)
	{
		index_pivot = quick_sort_partition(array, lowerbound, upperbound, size);
		quick_sort_recurision(array, lowerbound, index_pivot - 1, size);
		quick_sort_recurision(array, index_pivot + 1, upperbound, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: arry to sort
 * @size: number of elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
	{
		return;
	}
	quick_sort_recurision(array, 0, size - 1, size);
}
