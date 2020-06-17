#include "sort.h"
#include <stdio.h>
/**
 * merge - merge func
 * @array: passed arr
 * @size: size of array
 * @mid: midpoint
 * @tmp: tmp array
 */
void merge(int *array, int size, int mid, int *tmp)
{
	int j;
	int i = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);
	for (j = mid ; k < size; k++)
	{
		if (j == size)
		{
			tmp[k] = array[i];
			++i;
		}
		else if (i == mid || array[j] < array[i])
		{
			tmp[k] = array[j];
			++j;
		}
		else
		{
			tmp[k] = array[i];
			++i;
		}
	}
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	printf("[Done]: ");
	print_array(tmp, size);
}
/**
 * merge_topdown - drives topdown merge recursion
 * @array: passed arr
 * @size: size of arr
 * @tmp: tmp array
 */
void merge_topdown(int *array, size_t size, int *tmp)
{
	int mid;

	if (size < 2)
		return;
	mid = size / 2;
	merge_topdown(array, mid, tmp);
	merge_topdown(array + mid, size - mid, tmp);
	merge(array, size, mid, tmp);
}
/**
 * merge_sort - merge sort with topdown
 * @array: passed arr
 * @size: size of arr
 */
void merge_sort(int *array, size_t size)
{
	int *tmp = NULL;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	merge_topdown(array, size, tmp);
	free(tmp);
	tmp = NULL;
}
