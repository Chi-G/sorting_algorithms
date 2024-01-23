#include "sort.h"

/**
 * swap_pos - func that swaps position of values in array
 *
 * @array: the array to be changed
 * @first: the first index
 * @second: the second index
 */
void swap_pos(int **array, size_t first, size_t second)
{
	int holder;

	holder = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = holder;
}

/**
 * partition - func that splits the array into two parts
 * part lower than the sorted index and a part higher
 *
 * @array: the array to be sorted
 * @lower: the lower boundary
 * @upper: the upper boundary
 * @size: the size of the array
 *
 * Return: index of sorted pivot
 */
size_t partition(int **array, size_t lower, size_t upper, size_t size)
{
	size_t before, after, pivot;

	pivot = upper;
	before = lower;

	for (after = before; after < upper; after++)
	{
		if ((*array)[after] <= (*array)[pivot])
		{
			if (before != after)
			{
				swap_pos(array, before, after);
				print_array(*array, size);
			}
			before += 1;
		}
	}

	if (before != after)
	{
		swap_pos(array, before, after);
		print_array(*array, size);
	}
	return (before);
}

/**
 * sorter - func that recursively sorts the array given
 *
 * @array: the array to be sorted
 * @lb: the lower bound
 * @ub: the upper bound
 * @size: the size of the array
 */
void sorter(int **array, size_t lb, size_t ub, size_t size)
{
	size_t sorted_index;

	if (lb < ub && *array)
	{
		sorted_index = partition(array, lb, ub, size);

		if (sorted_index - lb > 1)
			sorter(array, lb, sorted_index - 1, size);

		if (ub - sorted_index > 1)
			sorter(array, sorted_index + 1, ub, size);
	}
}

/**
 * quick_sort - func that applies quick sort algorithm to sort
 * a given array
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sorter(&array, 0, size - 1, size);
}
