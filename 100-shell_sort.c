#include "sort.h"


/**
 * shell_sort - sory array using quick sort method
 * @array: input array
 * @size: input size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	if (size < 2)
		return;

	while (gap < size)
		gap = gap * 3 + 1;

	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		insertion_sort_array(array, size, gap);
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

/**
 * insertion_sort_array - sort an array of integers based insert sort
 *
 * @array: array
 * @size: size of array
 * @gap: gap given by shell sort
 * Return: void
 */
void insertion_sort_array(int *array, int size, int gap)
{
	int i, j, temp;

	i = j = temp = 0;

	for (i = gap; i < size; i++)
	{
		temp = array[i];
		j = i - gap;
		while ((temp < array[j]) && (j >= 0))
		{
			array[j + gap] = array[j];
			j -= gap;
		}
		array[j + gap] = temp;
	}
}
