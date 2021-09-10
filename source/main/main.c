#include "../../includes/push_swap.h"

static int	is_repeated(char **argv, int number, int i)
{
	int	j;

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

int	main(int argc, char *argv[])
{
	t_stack	stack;
	int		*normalized;

	if (argc < 2)
		return (0);
	argc--;
	argv = &argv[1];
	if (argc == 1)
		argv = check_params(&argc, argv);
	check_args(argc, argv);
	init_stacks(&stack);
	normalized = normalized_by_index(argv, argc);
	init_stack_a(&stack.a, argc, normalized);
	largest_data(&stack);
	sort_stack(&stack, argc);
	free(normalized);
	ft_dlstclear(&stack.a);
	if (stack.b)
		ft_dlstclear(&stack.b);
	return (0);
}
