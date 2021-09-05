#include "../includes/push_swap.h"
#include <stdio.h>

void    first_smallest(t_stack *stack)
{
    int     position;
    int     smallest;
    t_dlist *current;

    position = 1;
    current = stack->a;
    smallest = current->data;
    while (current->next != NULL)
    {
        current = current->next;
        if (current->data < smallest)
        {
            smallest = current->data;
            position++;
        }
    }
    printf("position smallest: %d\n", position);
    //push_smallest_to_b(stack, position);
}


void    sort_five_nodes(t_stack *stack)
{
    first_smallest(stack);
    //second_smallest(stack);
    //sort_three_nodes(stack);
    //push_a(stack);
    //push_a(stack);
}