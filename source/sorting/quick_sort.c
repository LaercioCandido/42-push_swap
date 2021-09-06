#include "../../includes/push_swap.h"

static int	partition(int *array, int start, int end)
{
	int		i;
	int		j;
	double	pivot;
	double	temp;

	pivot = array[start];
	i = start;
	j = start + 1;
	while (j <= end)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
		j++;
	}
	temp = array[start];
	array[start] = array[i];
	array[i] = temp;
	return (i);
}

void	quick_sort(int *array, int start, int end)
{
	int	i;

	i = 0;
	if (start < end)
	{
		i = partition(array, start, end);
		quick_sort(array, start, i - 1);
		quick_sort(array, i + 1, end);
	}
}
