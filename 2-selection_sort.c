#include "sort.h"
/**
 * selection_sort-  sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: arry to sort
 * @size: number of elements
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j = 0;
	int temp, place = 0;

	while(i < size)
	{
		int min = array[i];

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				place = j;
			}
		}

		if (min != array[i])
		{
			temp = array[place];
			array[place] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		
		i++;
	}
}
