#include "../../includes/push_swap.h"

void	push_a(t_stack	*stack)
{
	t_dlist	*top_b;
	int		number;

	if (stack->b == NULL)
		return ;
	top_b = stack->b;
	number = top_b->data;
	stack->b = top_b->next;
	free(top_b);
	if (stack->a == NULL)
		stack->a = ft_dlstnew(number);
	else
		ft_dlstadd_front(&stack->a, ft_dlstnew(number));
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack	*stack)
{
	t_dlist	*top_a;
	int		number;

	if (stack->a == NULL)
		return ;
	top_a = stack->a;
	number = top_a->data;
	stack->a = top_a->next;
	free(top_a);
	if (stack->b == NULL)
		stack->b = ft_dlstnew(number);
	else
	{
		ft_dlstadd_front(&stack->b, ft_dlstnew(number));
	}
	ft_putstr_fd("pb\n", 1);
}
