#include "sort.h"

/**
 * subarray_merge - Sorts a subarray of integers.
 * @sub_array: A subarray of an array of integers to sort.
 * @holder: A buffer to store the sorted subarray.
 * @up_bound: The upper bound index of the array.
 * @mid: The middle index of the array.
 * @low_bound: The lower bound index of the array.
 */
void subarray_merge(int *sub_array, int *holder, size_t up_bound, size_t mid,
		size_t low_bound)
{
	size_t idx, j, key = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_array + up_bound, mid - up_bound);

	printf("[right]: ");
	print_array(sub_array + mid, low_bound - mid);

	for (idx = up_bound, j = mid; idx < mid && j < low_bound; key++)
		holder[key] = (sub_array[idx] < sub_array[j])
			? sub_array[idx++] : sub_array[j++];
	for (; idx < mid; idx++)
		holder[key++] = sub_array[idx];
	for (; j < low_bound; j++)
		holder[key++] = sub_array[j];
	for (idx = up_bound, key = 0; idx < low_bound; idx++)
		sub_array[idx] = holder[key++];

	printf("[Done]: ");
	print_array(sub_array + up_bound, low_bound - up_bound);
}

/**
 * merge_sort_recursion - applies the merge sort algorithm through recursion.
 * @sub_array: subarray of an array of integers to sort.
 * @holder: buffer to store the sorted result.
 * @up_bound: The upper bound index of the subarray.
 * @low_bound: The lower bound index of the subarray.
 */
void merge_sort_recursion(int *sub_array, int *holder, size_t up_bound,
			  size_t low_bound)
{
	size_t mid;

	if (low_bound - up_bound > 1)
	{
		mid = up_bound + (low_bound - up_bound) / 2;
		merge_sort_recursion(sub_array, holder, up_bound, mid);
		merge_sort_recursion(sub_array, holder, mid, low_bound);
		subarray_merge(sub_array, holder, up_bound, mid, low_bound);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *holder;

	if (array == NULL || size < 2)
		return;

	holder = malloc(sizeof(int) * size);
	if (holder == NULL)
		return;

	merge_sort_recursion(array, holder, 0, size);

	free(holder);
}
