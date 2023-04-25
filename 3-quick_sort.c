#include "sort.h"

void divide(int beg, int pivot, int *i, size_t size);
int partition(int beg, int pivot, int *i, size_t size);
void swap_int(int *a, int *b);
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	int beg = 0, pivot;

	if (array && size > 1)
	{
		pivot = (size - 1);
		divide(beg, pivot, array, size);
	}
}
/**
* divide - recursively partition
* @beg: beginning of divided array
* @pivot: end of divided array
* @i: the beginning of the array
* @size: size of array
**/
void divide(int beg, int pivot, int *i, size_t size)
{
	int first, second, np;

	if (beg < pivot)
	{
		second = partition(beg, pivot, i, size);
		first = beg;
		np = second - 1;
		if (first != np && second != pivot)
			np--;
		divide(first, np, i, size);
		divide(second, pivot, i, size);
	}
}
/**
* partition - divides an array
* @beg: beginning of array separated
* @pivot: end of array separated
* @i: the beginning of array
* @size: size of array
* Return: the new beginning
**/
int partition(int beg, int pivot, int *i, size_t size)
{
	int temp;

	temp = beg;
	while (temp != pivot)
	{
		if (i[temp] < i[pivot])
		{
			if (temp != beg)
			{
				i[temp] = i[beg] ^ i[temp];
				i[beg] = i[beg] ^ i[temp];
				i[temp] = i[beg] ^ i[temp];
				print_array(i, size);
			}
			temp++;
			beg++;
		}
		else
			temp++;
	}
	if (beg != pivot)
	{
		if (i[beg] > i[pivot])
		{
			i[pivot] = i[beg] ^ i[pivot];
			i[beg] = i[beg] ^ i[pivot];
			i[pivot] = i[beg] ^ i[pivot];
			print_array(i, size);
		}
		beg++;
	}
	return (beg);
}
