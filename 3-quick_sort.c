#include "sort.h"

/**
 * quick_sort -  function to sort an array of integers using the quick sort
 * algorithm
 */
/**
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
void swap_values(int *a, int *b) {
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

int partition_sort(int *array, size_t size, int left, int right) {
  int pivot = array[right];
  int i = left;
  int j;

  for (j = left; j < right; j++) {
    if (array[j] <= pivot) {
      swap_values(&array[i], &array[j]);
      print_array(array, size);
      i++;
    }
  }
  swap_values(&array[i], &array[right]);
  print_array(array, size);
  return i;
  /*while (start < end)
    {
      while (array[start] <= pivot)
        {
          start++;
        }
      while (array[end] > pivot)
        {
          end--;
        }
      if (start > end)
      {
        swap_values(&array[left], &array[end]);
        print_array(array, size);
      }
    }
  swap_values(&array[left], &array[end]);
  return (end);*/
}

void quick_sort_helper(int *array, size_t size, int left, int right) {
  int pivot;

  if (left < right) {
    pivot = partition_sort(array, size, left, right);
    quick_sort_helper(array, size, left, pivot - 1);
    quick_sort_helper(array, size, pivot + 1, right);
  }
}

void quick_sort(int *array, size_t size) {
  if (array == NULL || size < 2)
    return;
  quick_sort_helper(array, size, 0, size - 1);
}
