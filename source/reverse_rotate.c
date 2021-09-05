#include "../includes/push_swap.h"

static void	reverse_rotate_list(t_dlist **stack)
{
	t_dlist	*head;
    t_dlist *last;
    t_dlist *pointer;
    int     number;

	head = *stack;
    last = ft_dlstlast(*stack);
	if (head == NULL || last == NULL || pointer == NULL)
		return ;
    pointer = last->previous;
    pointer->next = NULL;
    number = last->data;
    ft_dlstadd_front(stack, ft_dlstnew(number));
	head = head->previous;
	*stack = head;
}

void	reverse_rotate_a(t_stack *stack)
{
	reverse_rotate_list(&stack->a);
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_stack *stack)
{
	reverse_rotate_list(&stack->b);
	ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_both(t_stack *stack)
{
	reverse_rotate_list(&stack->a);
	reverse_rotate_list(&stack->b);
	ft_putstr_fd("rrr\n", 1);
}
