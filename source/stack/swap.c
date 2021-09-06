#include "../../includes/push_swap.h"

void	swap_nodes(t_dlist *first, t_dlist *second)
{
	int	aux;

	aux = first->data;
	first->data = second->data;
	second->data = aux;
}

void	swap_a(t_stack *stack)
{
	swap_nodes(stack->a, stack->a->next);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack *stack)
{
	swap_nodes(stack->b, stack->b->next);
	ft_putstr_fd("sb\n", 1);
}

void	swap_both(t_stack *stack)
{
	swap_nodes(stack->a, stack->a->next);
	swap_nodes(stack->b, stack->b->next);
	ft_putstr_fd("ss\n", 1);
}