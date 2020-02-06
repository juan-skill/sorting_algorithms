#include "sort.h"


/**
 * quick_sort_hoare - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 *
 * @array: array
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
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
	int pivot = 0;

	if (beg < end)
	{
		pivot = partition(array, beg, end, size);
		sort(array, beg, pivot, size);
		sort(array, pivot + 1, end, size);
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
	int left, right, pivot = array[end];

	left = beg - 1;
	right = end + 1;

	while (1)
	{
		do
			left++;
		while (array[left] < pivot);

		do
			right--;
		while (array[right] > pivot);

		if (left > right)
			return (right);

		if (left == right)
			return (right - 1);

		swap(&array[left], &array[right]);
		print_array(array, size);
	}
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
