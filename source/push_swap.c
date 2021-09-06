#include "../includes/push_swap.h"
#include <stdio.h>

// funções aninhadas
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	return_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

//fçoes aninhadas



size_t	ft_strlen(const char *frase)
{
	int i;

	i = 0;
	while (frase[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int		count_size(char const *s, char c)
{
	int tamanho;
	int controle;
	int i;

	i = 0;
	tamanho = 0;
	controle = 0;
	while (s[i] != '\0' && s[0] != '\0')
	{
		if (s[i] != c && controle == 0)
		{
			controle = 1;
			tamanho++;
		}
		else if (s[i] == c)
			controle = 0;
		i++;
	}
	return (tamanho);
}

static char		*ret(const char *fr, int inicial, int final)
{
	char	*string;
	int		i;

	i = 0;
	string = (char*)malloc((final - inicial + 1) * sizeof(char));
	while (final > inicial)
	{
		string[i] = fr[inicial];
		i++;
		inicial++;
	}
	string[i] = '\0';
	return (string);
}

char			**ft_split(const char *s, char c)
{
	char	**split;
	int		inicial;
	size_t	i;
	size_t	j;

	if (s == 0)
		return (NULL);
	i = -1;
	j = 0;
	inicial = -1;
	split = malloc((count_size(s, c) + 1) * sizeof(char*));
	if (split == 0)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && inicial < 0)
			inicial = i;
		else if ((s[i] == c || i == ft_strlen(s)) && inicial >= 0)
		{
			split[j++] = ret(s, inicial, i);
			inicial = -1;
		}
	}
	split[j] = NULL;
	return (split);
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

///// fçoes aninhadas

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;
	size_t	len;

	len = count * size;
	mem = malloc(len);
	if (mem == 0)
		return (0);
	i = 0;
	while (len > 0)
	{
		mem[i] = '\0';
		i++;
		len--;
	}
	return (mem);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	atoi_isspace(int c)
{
	if (c == ' ' || c == '\v' || c == '\n'
		|| c == '\t' || c == '\r' || c == '\f')
	{
		return (1);
	}
	return (0);
}

double	ft_atoi(const char *nptr)
{
	double	number;
	int		sign;

	number = 0;
	sign = 1;
	while (atoi_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		number *= 10;
		number += (*nptr - '0');
		nptr++;
	}
	number *= sign;
	return (number);
}

//////

t_dlist	*ft_dlstnew(int data)
{
	t_dlist	*pointer;

	pointer = (t_dlist *)malloc(sizeof(t_stack));
	if (!(pointer))
		return_error();
	pointer->data = data;
	pointer->next = NULL;
	pointer->previous = NULL;
	return (pointer);
}

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*pointer;

	pointer = *lst;
	*lst = new;
	new->next = pointer;
	pointer->previous = new;
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	t_dlist	*pointer;

	if (lst == NULL)
		return (lst);
	pointer = lst;
	while (pointer->next != NULL)
	{
		pointer = pointer->next;
	}
	return (pointer);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*pointer;

	if (new == NULL)
		return ;
	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	pointer = ft_dlstlast(*lst);
	pointer->next = new;
	new->previous = pointer;
}

//////////////

static void	init_stacks(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->largest_number = INT_MIN;
}

//void init_stack_a(t_dlist **stack_a, int argc, char **argv)
void init_stack_a(t_dlist **stack_a, int argc, int *normalized)
{
	//int number;
	int i;

	i = 0;
	//number = (int)ft_atoi(argv[i]);
	*stack_a = ft_dlstnew(normalized[i]);
	while (i < (argc - 1))
	{
		i++;
		//number = (int)ft_atoi(argv[i]);
		ft_dlstadd_back(stack_a, ft_dlstnew(normalized[i]));
	}
}

static void	setup_array_from_argv(char **argv, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi(argv[i]);
		i++;
	}
}

int	*normalized_by_index(char **argv, int size)
{
	int		i;
	int		*original;
	int		*sorted;
	int		*normalized;
	int		j;

	original = (int *)ft_calloc(sizeof(int), size);
	sorted = (int *)ft_calloc(sizeof(int), size);
	normalized = (int *)ft_calloc(sizeof(int), size);
	setup_array_from_argv(argv, original, size);
	setup_array_from_argv(argv, sorted, size);
	quick_sort(sorted, 0, size - 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (original[i] != sorted[j])
			j++;
		normalized[i] = j;
		i++;
	}
	free(original);
	free(sorted);
	return (normalized);
}

///////////////

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
		

	return (0);
}
