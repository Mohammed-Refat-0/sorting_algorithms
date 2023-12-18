#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the bubble sort algorithm
 * @array: arry to sort
 * @size: number of elements
 */
void bubble_sort(int *array, size_t size)
{
	int flag = 1;
	int temp;
	size_t i, j, k = 0;

	for (i = 0; i < size; i++)
	{
		if (flag == 0)
		{
			break;
		}
		flag = 0;
		j = 0;
		k = 1;
		while (j < size - 1)
		{
			if (array[j] > array[k])
			{
				temp = array[j];
				array[j] = array[k];
				array[k] = temp;
				flag = 1;
			}
			j++;
			k++;
		}
		print_array(array, size);
	}
}
