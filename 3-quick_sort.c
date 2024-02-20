#include "sort.h"
/*
 * select pivot element a[n - 1]
 * partition the array into two subarrays: start and end
 * loop as long as start < end
 * if a[start] < pivot, start++
 * if a[end] > pivot, end--
 * if start < end, swap a[start] and a[end]
 * print array
 * else, swap a[end] with pivot
 * print array
 * return end
 */
/**
 * swap_values - swaps two values
 * @a: first value
 * @b: second value
 */
void swap_values(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition_sort - does a partition sort on an array, then returns
 * the index where the partition starts
 * @array: array to sort
 * @size: size of array
 * @left: lower bound
 * @right: upper bound
 * Return: index where the patition starts
 */
int partition_sort(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i = left;
	int j;

	for (j = left; j < right; j++)
	{
		if (array[j] <= pivot)
		{
			swap_values(&array[i], &array[j]);
			print_array(array, size);
			i++;
		}
	}
	swap_values(&array[i], &array[right]);
	print_array(array, size);
	return (i);
}
/**
 * quick_sort_helper - recursive implementation of the quick sort method
 * @array: array to sort
 * @size: size of array
 * @left: lower bound
 * @right: upper bound
 */
void quick_sort_helper(int *array, size_t size, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = partition_sort(array, size, left, right);
		quick_sort_helper(array, size, left, pivot - 1);
		quick_sort_helper(array, size, pivot + 1, right);
	}
}
/**
 * quick_sort - sorts an array in acsending order using the quick sort method
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, size, 0, size - 1);
}
