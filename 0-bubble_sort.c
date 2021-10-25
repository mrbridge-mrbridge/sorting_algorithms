#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * bubble_sort - sorts in buble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: None
 */

void bubble_sort(int *array, size_t size)
{
	if(array == NULL || size < 2)
		return;
	
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - 1 - i; j++)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;

				print_array(array, size)
			}
		}
	}
}
