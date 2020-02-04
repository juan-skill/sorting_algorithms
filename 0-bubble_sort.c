#include "sort.h"


/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 *
 * @array: input array
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int flag;

	if (array == NULL || size < 2)
		return;

	while (flag)
	{
		flag = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(&array[i], &array[i - 1]);
				print_array(array, size);
				flag = 1;
			}
		}
	}
}


/**
 * swap - swap two arrays
 * @pa: ptr to array element
 * @pb: prt to array element
 */
void swap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
