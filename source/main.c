#include "../includes/push_swap.h"
#include <stdio.h>


static int is_repeated(char **argv, int number, int i)
{
	int j;
	
	j = 0;
	while (j < i)
	{
		if (ft_atoi(argv[j]) == number)
			return (1);
		j++;
	}
	return (0);
}

static void	check_type_arg(char **argv, int i)
{
	int		j;
	double	number;

	j = 0;
	if (argv[i][j] == '-' || argv[i][j] == '+')
	{
		j++;
		if (!argv[i][j])
			return_error();
	}
	while (argv[i][j])
	{
		if (!(ft_isdigit(argv[i][j])))
			return_error();
		j++;
	}
	number = ft_atoi(argv[i]);
	if (is_repeated(argv, number, i))
		return_error();
	if (number < INT_MIN || number > INT_MAX)
		return_error();
}

static void	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		check_type_arg(argv, i);
		i++;
	}
}

void		largest_data(t_stack *stack)
{
	t_dlist *current;

	current = stack->a;
	while (current)
	{
		if (current->data > stack->largest_data)
			stack->largest_data = current->data;
		//printf("stack->a: %i\n", current->data);
		current = current->next;
	}
}

static char	**check_params(int *argc, char **argv)
{
	int	i;

	i = 0;
	if (!(argv[0][0]))
		return (0);
	argv = ft_split(argv[0], ' ');
	while (argv[i] != NULL)
		i++;
	*argc = i;
	return (argv);
}


int main(int argc, char *argv[])
{
	t_stack	stack;
	int		*normalized;

	if (argc < 2)
		return (0);
	//reset_flags;
	argc--;
	argv = &argv[1];
	if (argc == 1)
		argv = check_params(&argc, argv);
	check_args(argc, argv);
    init_stacks(&stack);
	normalized = normalized_by_index(argv, argc);
	/*
	int i = 0;
	while (i < 2)
	{
		printf("normalized[%d] = %d\n", i, normalized[i]);
		i++;
	}
	*/
	//init_stack_a(&stack.a, argc, argv);
	init_stack_a(&stack.a, argc, normalized);
	largest_data(&stack); //	//stack->largest_data = argc;
	sort_stack(&stack, argc);

	/*
	printf("argumento A: %i\n", stack.a->data);
	while (stack.a->next != NULL)
	{
		stack.a = stack.a->next;
		printf("argumento A: %i\n", stack.a->data);
	}

	
	if (stack.b != NULL)
		printf("\nargumento B: %i\n", stack.b->data);
	while (stack.b->next != NULL)
	{
		stack.b = stack.b->next;
		printf("argumento B: %i\n", stack.b->data);
	}
	*/
		
	free(normalized);
	return (0);
}
