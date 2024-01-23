#include "sort.h"

/**
 * swap - func that swaps position of values in array
 * @array: the array to be changed
 * @first: the first index
 * @second: the second index
 *
 * Return: nothing
 */
void swap(int **array, int first, int second)
{
	int holder;

	holder = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = holder;
}

/**
 * build_Max_Heap - func that builds a heap from an array
 * @array: the array to be changed to heap array
 * @end_index: the end index as array is partitioned
 * @start_index: the starting point index as array is sorted
 * @a_size: the array size unchanged
 *
 * Return: nothing
 */
void build_Max_Heap(int *array, int end_index, int start_index, int a_size)
{
	int largest, left, right;

	largest = start_index;
	left = (start_index * 2) + 1;
	right = (start_index * 2) + 2;

	if (left < end_index && array[left] > array[largest])
		largest = left;

	if (right < end_index && array[right] > array[largest])
		largest = right;

	if (largest != start_index)
	{
		swap(&array, start_index, largest);
		print_array(array, a_size);
		build_Max_Heap(array, end_index, largest, a_size);
	}
}

/**
 * heap_sort - func that sorts an array using the Heap sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int start_index, i;

	if (!array || size < 2)
		return;

	start_index = ((int)size - 1) / 2;

	/*Build max heap*/
	for (i = start_index; i >= 0; i--)
	{
		build_Max_Heap(array, size, i, size);
	}

	/*Destroy max heap and print sorted array*/
	for (i = size - 1; i > 0; i--)
	{
		swap(&array, 0, i);
		print_array(array, size);
		build_Max_Heap(array, i, 0, size);
	}
}
