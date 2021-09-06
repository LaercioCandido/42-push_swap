#include "../includes/push_swap.h"

void    sort_three_nodes(t_stack *stack)
{
    int first;
    int second;
    int third;
    t_dlist *pointer;

    pointer = stack->a->next;
    first = pointer->previous->data;
    second = pointer->data;
    third = pointer->next->data;
    if ((first < second && first < third && second > third) ||
        (first > second && first < third && second < third) ||
        (first > second && first > third && second > third))
        swap_a(stack);
    pointer = stack->a->next;
    first = pointer->previous->data;
    second = pointer->data;
    third = pointer->next->data; 
    if (first > second && first > third && second < third)
        rotate_a(stack);
    if (first < second && first > third && second > third)
        reverse_rotate_a(stack);
}

int     stack_ordered(t_stack *stack, int size)
{
	int		i;
	int		number;
	t_dlist	*current;

	i = 1;
	number = stack->a->data;
	current = stack->a->next;
	while (i < size)
	{
		if (number > current->data)
			return (1);
		number = current->data;
		current = current->next;
		i++;
	}
	return (0);
}

void	sort_stack(t_stack *stack, int qtt_node)
{
    if (stack_ordered(stack, qtt_node) == 0)
        return ;
    else if (qtt_node == 2)
        swap_a(stack);
    else if (qtt_node == 3)
        sort_three_nodes(stack);
    else if (qtt_node <= 5)
        sort_five_nodes(stack, qtt_node);/*
    else
        radix_sort(stack);
        */
}
