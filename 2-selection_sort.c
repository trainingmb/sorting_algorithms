#include "sort.h"
void swap_int(int *a, int *b);
/**
* selection_sort - a function that sorts an array of integers in ascending
* order using the selection sort algorithm
* @array: array of integers
* @size: size of array
**/
void selection_sort(int *array, size_t size)
{
	size_t j, i;
	int *temp;

	temp = NULL;
	for (j = 0; array && j < size - 1; j++)
	{
		temp = NULL;
		for (i = j + 1; i < size; i++)
		{
			if (array[i] < array[j])
			{
				if (temp && array[i] < *temp)
					temp = &array[i];
				if (!temp)
					temp = &array[i];
			}
		}
		if (temp)
		{
			*temp = *temp ^ array[j];
			array[j] = *temp ^ array[j];
			*temp = *temp ^ array[j];
			print_array(array, size);
		}
	}
}
