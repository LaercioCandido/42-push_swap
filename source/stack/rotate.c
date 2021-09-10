#include "../../includes/push_swap.h"

static void	rotate_list(t_dlist **stack)
{
	t_dlist	*head;
	int		number;

	head = *stack;
	if (head == NULL)
		return ;
	number = head->data;
	ft_dlstadd_back(stack, ft_dlstnew(number));
	*stack = head->next;
	free(head);
}

void	rotate_a(t_stack *stack)
{
	rotate_list(&stack->a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack *stack)
{
	rotate_list(&stack->b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_stack *stack)
{
	rotate_list(&stack->a);
	rotate_list(&stack->b);
	ft_putstr_fd("rr\n", 1);
}
