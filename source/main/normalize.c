#include "../../includes/push_swap.h"

void	init_stacks(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->largest_data = INT_MIN;
}

void	init_stack_a(t_dlist **stack_a, int argc, int *normalized)
{
	int	i;

	i = 0;
	*stack_a = ft_dlstnew(normalized[i]);
	while (i < (argc - 1))
	{
		i++;
		ft_dlstadd_back(stack_a, ft_dlstnew(normalized[i]));
	}
}

static void	setup_array_from_argv(char **argv, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi(argv[i]);
		i++;
	}
}

int	*normalized_by_index(char **argv, int size)
{
	int	i;
	int	*original;
	int	*sorted;
	int	*normalized;
	int	j;

	original = (int *)ft_calloc(sizeof(int), size);
	sorted = (int *)ft_calloc(sizeof(int), size);
	normalized = (int *)ft_calloc(sizeof(int), size);
	setup_array_from_argv(argv, original, size);
	setup_array_from_argv(argv, sorted, size);
	quick_sort(sorted, 0, size - 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (original[i] != sorted[j])
			j++;
		normalized[i] = j;
		i++;
	}
	free(original);
	free(sorted);
	return (normalized);
}

void	largest_data(t_stack *stack)
{
	t_dlist	*current;

	current = stack->a;
	while (current)
	{
		if (current->data > stack->largest_data)
			stack->largest_data = current->data;
		current = current->next;
	}
}
