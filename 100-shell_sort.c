#include "sort.h"
/**
 * shell_sort - Sorts an array of integers using the
 * Shell sort algorithm and knuth shuffle
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: Nothing
 * Description: This function sorts an array of integers in ascending order
 */

void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j, tmp;

	while (gap < ((int)(size)))
		gap = (3 * gap) + 1;
	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < (int)size; i += 1)
		{
			tmp = array[i];

			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];

			array[j] = tmp;
		}
		print_array(array, size);
	}
}
