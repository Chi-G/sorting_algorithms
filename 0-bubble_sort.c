#include "sort.h"

/**
 * swap_pos - this function swaps positions of values in an array
 *
 * @array: the array to be changed
 * @first: the first index
 * @second: the second index
 */
void swap_pos(int **array, size_t first, sizte_t second)
{
	int holder;

	holder = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = holder;
}

/**
 * bubble_sort - function for sorting algorithm that sorts in form
 * of a bubble
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, flag;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_pos(&array, j, j + 1);
				print_array(array, size);
				flag = 1;
			}
		}

		if (!flag)
			break;
	}
}
