#include "../../includes/push_swap.h"

int	get_bit(int largest_data, int i)
{
	return ((largest_data >> i) & 1);
}

int	most_significant_bit(int largest_data)
{
	int	i;

	i = 31;
	while (get_bit(largest_data, i) != 1)
		i--;
	return (i);
}

int	remaining_nodes_are_ordered(t_stack *stack)
{
	t_dlist	*current;
	int		i;
	int		size_list;

	i = 0;
	size_list = ft_dlstsize(stack->a);
	current = stack->a;
	while (i < size_list - 1)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

static void	push_bits_on_zero(t_stack *stack, int i)
{
	int	j;

	j = 0;
	while (j < (stack->largest_data + 1))
	{
		if (get_bit(stack->a->data, i) == 0)
			push_b(stack);
		else
			rotate_a(stack);
		if (remaining_nodes_are_ordered(stack))
			break ;
		j++;
	}
}

void	radix_sort(t_stack *stack)
{
	int	i;
	int	count;

	i = 0;
	count = most_significant_bit(stack->largest_data);
	while (i <= count)
	{
		push_bits_on_zero(stack, i);
		while (stack->b != NULL)
			push_a(stack);
		i++;
	}
}
