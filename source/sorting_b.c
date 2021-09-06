#include "../includes/push_swap.h"
#include <stdio.h>

void     push_second_smallest_to_b(t_stack *stack, int position)
{
	if (position == 2)
		swap_a(stack);
	if (position == 3)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	if (position == 4)
		reverse_rotate_a(stack);
    if (stack_ordered(stack, 4) == 1)
        push_b(stack);
}

void    push_smallest_to_b(t_stack *stack, int position)
{
    if (position == 2)
		swap_a(stack);
	if (position == 3)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	if (position == 4)
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
	}
	if (position == 5)
		reverse_rotate_a(stack);
    if (stack_ordered(stack, 5) == 1)
    	push_b(stack);
}

void    find_first(t_stack *stack)
{
    int     i;
    int     position;
    int     smallest;
    t_dlist *current;

    i = 2;
    position = 1;
    smallest = stack->a->data;
    current = stack->a;
    //while (i <= qtt_nodes)
    while (current->next != NULL)
    {
        current = current->next;
        if (current->data < smallest)
        {
            smallest = current->data;
            position = i;
        }
        //current = current->next;
        i++;
    }
    //printf("position smallest: %d\n", position);
    //if (i == 5 && stack_ordered(stack, 4) == 0)
    //    exit (1);
    if (i == 6)
        push_smallest_to_b(stack, position);
    else
        push_second_smallest_to_b(stack,position);
    //return (position);
}


void    sort_five_nodes(t_stack *stack, int qtt_nodes)
{
    int     position;

    if (qtt_nodes == 5)
		find_first(stack);
    find_first(stack);
    if (stack_ordered(stack, 4) == 1)
        sort_three_nodes(stack);
    if (qtt_nodes == 5 && stack->b != NULL)
        push_a(stack);
    if (stack->b != NULL)
        push_a(stack);
}