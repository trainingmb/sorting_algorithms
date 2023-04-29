#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * using Bubble Sort
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	char changed;

	changed = 'a';
	while (changed == 'a')
	{
		changed = 'b';
		i = 1;
		while (array && i < size)
		{
			if (array[i] < array[i - 1])
			{  
				array[i]     = array[i] ^ array[i - 1];
				array[i - 1] = array[i] ^ array[i - 1];
				array[i]     = array[i] ^ array[i - 1];
				changed = 'a';
				print_array(array, size);
			}
			i++;
		}

	}
}
