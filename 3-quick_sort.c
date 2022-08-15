#include "sort.h"
/**
  *quick_sort - sorts the elements using quicksort algorithm
  * @array: list of elements for sorting
  * @size: size of the array to be sorted
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	sort(array, 0, size - 1, size);
}
/**
  *sort - sorts the sub arrays from partition
  * @array: points the the array
  * @start: leftmost element in the sub-arrays
  * @end: rightmost element in the sub-arrays
  * @size: size of the sub-arrays
 */

void sort(int *array, int start, int end, size_t size)
{
	int new_loc;

	if (start < end)
	{
		new_loc = Partition(array, start, end, size);
		sort(array, start, new_loc - 1, size);
		sort(array, new_loc + 1, end, size);
	}
}
/**
  *Partition - partions the array with the pivot having
  *	elements less than itself to the left and
  *	elements greater to the right
  * @array: points to the array
  * @start: leftmost element in the array
  * @end: Rightmost ellement in the array
  * @size: size of the array
  *
  * Return: return the pivot index position after
  *	partitioning
 */

int Partition(int *array, int start, int end, size_t size)
{
	int i, P_index, pivot, tmp;

	pivot = array[end];
	P_index = start;

	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			if (P_index != i)
			{
				tmp = array[i];
				array[i] = array[P_index];
				array[P_index] = tmp;
				print_array(array, size);
			}
			P_index++;
		}
	}
	if (array[P_index] != array[end])
	{
		tmp = array[P_index];
		array[P_index] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	return (P_index);
}
