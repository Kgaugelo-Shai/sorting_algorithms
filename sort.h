#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort(int *array, size_t start, size_t end);
void cocktail_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
int arr_max(int *array, size_t size);
void merge_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t index, size_t nth);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

/* These are for testing purposes */
int partition_sort(int *array, size_t size, int left, int right);
void swap_values(int *a, int *b);
void quick_sort_helper(int *array, size_t siz, int left, int right);

#endif
