#include "../includes/push_swap.h"
#include <stdio.h>

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
   	printf("significant: %i\n", i);
	return (i);
}

int	remaining_nodes_are_ordered(t_stack *stack)
{
	t_dlist	*current;
	//int		i;

	//i = 0;
	current = stack->a;
	//while (i < stack->nodes_on_a - 1)
    while (current)
	{
		if (current->data > current->next->data)
			return (1);
		current = current->next;
	//	i++;
	}
	return (0);
}

static void	push_bits_on_zero(t_stack *stack, int i)
{
	int	j;
    //t_dlist *current;

	j = 0;
	while (j < (stack->largest_data + 1))
    //current = stack->a;
    //while (current)
	{
		if (get_bit(stack->a->data, i) == 0)
			push_b(stack);
		else
			rotate_a(stack);
		if (remaining_nodes_are_ordered(stack))
			break ;
		j++;
        //current = current->next;
	}
}

void	radix_sort(t_stack *stack)
{
	int	i;
	int	loop_count;

	i = 0;
	loop_count = most_significant_bit(stack->largest_data);
	while (i <= loop_count)
	{
		push_bits_on_zero(stack, i);
		//return_nodes_to_a(stack);
        while (stack->b)
            push_a(stack);
		i++;
	}
}
