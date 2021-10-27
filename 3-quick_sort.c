#include "sort.h"

/**
 * lomuto - uses the lomuto scheme to find partition
 * @array: array to ebe sorted
 * @up: upper index of partition
 * @low: lower index of the partition
 * @size: array size
 *
 * Return: (i + 1) index
 */

size_t lomuto(int *array, ssize_t low, ssize_t up, size_t size)
{
	ssize_t i, j;
	int temp, mid;

	mid = array[up];
	i = low - 1;
	for (j = low; j < up; j++)
	{
		if (array[j] < mid)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[up] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[up];
		array[up] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * part_sort - sorts the partition
 * @array: array to be sorted
 * @up: upper index of partition
 * @low: lower index of partition
 * @size: size of array
 *
 * Return: Nothing
 */

void part_sort(int *array, ssize_t low, ssize_t up, size_t size)
{
	ssize_t mid;

	if (low < up)
	{
		mid = lomuto(array, low, up, size);
		part_sort(array, low, mid - 1, size);
		part_sort(array, mid + 1, up, size);

	}
}


/**
 * quick_sort - sorts an array using the quick sort
 * algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	part_sort(array, 0, size - 1, size);
}
