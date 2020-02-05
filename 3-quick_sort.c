#include "sort.h"


/**
 * quick_sort -  sorts an array of integers in ascending order using
 * the Quick sort algorithm
 *
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	/* beg = 0; */
	/* end = size - 1; */
	sort(array, 0, size - 1, size);
}


/**
 * sort - sorting the array using recursion
 * @array: input array
 * @beg: lower limit
 * @end: upper limit
 * @size: size of array
 */
void sort(int *array, int beg, int end, size_t size)
{
	int part;

	if (beg < end)
	{
		part = partition(array, beg, end, size);
		sort(array, beg, part - 1, size);
		sort(array, part + 1, end, size);
	}
}

/**
 * partition - partitions the array and swaps
 *
 * @array: input array
 * @beg: lower limit
 * @end: upper limit
 * @size: size of array
 * Return: the partioned index
 */
int partition(int *array, int beg, int end, size_t size)
{
	int pivot, pindex, k;

	pivot = array[end];
	k = pindex = beg;

	while (k < end)
	{
		if (array[k] <= pivot)
		{
			if (pindex != k)
			{
				swap(&array[pindex], &array[k]);
				print_array(array, size);
			}
			pindex++;
		}
		k++;
	}

	if (end != pindex)
	{
		swap(&array[pindex], &array[end]);
		print_array(array, size);
	}

	return (pindex);
}

/**
 * swap - swaps two elements
 *
 * @a: first integer
 * @b: second integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
