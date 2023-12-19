#include "sort.h"

/**
 * quick_sort_partition - helper function to partition, swap and print
 * array for the implmentation quick sort
 * @array: arry to sort
 * @lowerbound: lower limit to partition the array by
 * @upperbound: upper limit to partition the array by
 */
size_t quick_sort_partition(int *array, size_t lowerbound, size_t upperbound, size_t size)
{
    int temp;
    size_t j;
    size_t i = lowerbound - 1;
    int pivot = array[upperbound];

   for (j = lowerbound; j <= upperbound - 1; j++)
   {
       if (array[j] < pivot)
       {
           i++;
           temp = array[i];
           array[i] = array[j];
           array[j] = temp;
           print_array(array, size);
       }
   }
   temp = array[i + 1];
   array[i + 1] = array[upperbound];
   array[upperbound] = temp;
   print_array(array, size);
   return (i + 1);
}

/**
 * quick_sort_recurision-  recursive function to implment quick sort
 * @array: arry to sort
 * @lowerbound: lower limit to partition the array by
 * @upperbound: upper limit to partition the array by
 */
void quick_sort_recurision(int *array, size_t lowerbound, size_t upperbound, size_t size)
{
    if (upperbound > lowerbound)
    {
        size_t index_pivot = quick_sort_partition(array, lowerbound, upperbound, size);
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
    quick_sort_recurision(array, 0, size - 1, size);
}
