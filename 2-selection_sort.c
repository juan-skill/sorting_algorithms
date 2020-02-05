#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 *
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned int k, pos, tmp;

	k = pos = tmp = 0;

	if (size == 0 || array == NULL)
		return;

	for (k = 0; k < size - 1; k++)
	{
		pos = selection_smallest(array, k, size);
		if (pos != k)
		{
			swap(&array[k], &array[pos]);
			print_array(array, size);
		}
	}
}

/**
 * selection_smallest - find the smallest element in array
 *
 * @arr: array to find
 * @k: current position to start
 * @size: size of array
 * Return: the position where it is the smallest element
 */
int selection_smallest(int *arr, int k, int size)
{
	int pos = k, small = arr[k], i = 0;

	for (i = k + 1; i < size; i++)
	{
		if (arr[i] < small)
		{
			small = arr[i];
			pos = i;
		}
	}
	return (pos);
}


/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
