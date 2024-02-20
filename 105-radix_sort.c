#include "sort.h"

/**
 * find_max - Finds the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer.
 */
int find_max(int *array, int size)
{
	int max_value, i;

	for (max_value = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	return (max_value);
}

/**
 * radix_sort_helper - Sorts significant digits of an array
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @index: The significant digit to sort.
 * @holder: buffer to store sorted array.
 */
void radix_sort_helper(int *array, size_t size, int index, int *holder)
{
	int tracker[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		tracker[(array[i] / index) % 10] += 1;

	for (i = 0; i < 10; i++)
		tracker[i] += tracker[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		holder[tracker[(array[i] / index) % 10] - 1] = array[i];
		tracker[(array[i] / index) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = holder[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max_value, index, *holder;

	if (array == NULL || size < 2)
		return;

	holder = malloc(sizeof(int) * size);
	if (holder == NULL)
		return;

	max_value = find_max(array, size);
	for (index = 1; max_value / index > 0; index *= 10)
	{
		radix_sort_helper(array, size, index, holder);
		print_array(array, size);
	}

	free(holder);
}
