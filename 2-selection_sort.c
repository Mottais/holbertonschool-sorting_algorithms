#include "sort.h"

/**
 * swap - Swaps two elements of an array
 * @a: Integer a
 * @b: Integer b
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	/*Outer loop iterates through each element of the array*/
	for (i = 0; i < size - 1; i++)
	{
		/*Assume the current index is the index of the minimum element*/
		min_idx = i;

		/*Inner loop finds the index of the minimum element in the unsorted part*/
		for (j = i + 1; j < size; j++)
		{
			/*If a smaller element is found, update min_idx*/
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		/*If the minimum element is not at its original position, swap it*/
		if (min_idx != i)
		{
			/*Swap elements at the current index and index of the min element*/
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
