#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - The doubly linked node list
 *
 * @n: The integer node
 * @prev: The pointer of the previous element of the list node
 * @next: The pointer of the next element of the list node
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sort Algorithms prototypes */
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort_hoare(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void heap_sort(int *array, size_t size);
#endif /* SORT_H_ */
