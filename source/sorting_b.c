#include "../includes/push_swap.h"
#include <stdio.h>

void    first_smallest(t_stack *stack, int qtt_nodes)
{
    int     i;
    int     position;
    int     smallest;
    t_dlist *current;

    i = 2;
    position = 1;
    smallest = stack->a->data;
    current = stack->a->next;
    while (i <= qtt_nodes)
    {
        if (current->data < smallest)
        {
            smallest = current->data;
            position = i;
        }
        current = current->next;
        i++;
    }
    printf("position smallest: %d\n", position);
    //push_smallest_to_b(stack, position);
}


void    sort_five_nodes(t_stack *stack)
{
    first_smallest(stack, 5);
    //second_smallest(stack);
    //sort_three_nodes(stack);
    //push_a(stack);
    //push_a(stack);
}