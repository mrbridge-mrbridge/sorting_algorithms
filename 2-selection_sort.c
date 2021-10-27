#include "sort.h"

/**
 * selection_sort - sorts an array using the selection 
 * sort algorithm
 * @array: array to be sorted
 * @size: array size
 *
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		k = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}
		if (i != k)
		{
			temp = array[i];
			array[i] = array[k];
			array[k] = temp;
			print_array(array, size);
		}
	}
}
