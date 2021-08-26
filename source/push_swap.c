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

t_stack	*ft_dlstnew(int data)
{
	t_stack	*pointer;

	pointer = (t_stack *)malloc(sizeof(t_stack));
	if (!(pointer))
		return_error();
	pointer->data = data;
	pointer->next = NULL;
	pointer->previous = NULL;
	return (pointer);
}

t_stack	*ft_dlstlast(t_stack *lst)
{
	t_stack	*pointer;

	if (lst == NULL)
		return (lst);
	pointer = lst;
	while (pointer->next != NULL)
	{
		pointer = pointer->next;
	}
	return (pointer);
}

void	ft_dlstadd_back(t_stack *lst, t_stack *new)
{
	t_stack	*pointer;

	if (new == NULL)
		return ;
	if (lst == NULL)
	{
		lst = new;
		return ;
	}
	pointer = ft_dlstlast(lst);
	pointer->next = new;
	new->previous = pointer;
}

//////////////

static void	init_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a = NULL;
	stack_b = NULL;
}

void init_stack_a(t_stack *stack_a, int argc, char **argv)
{
	int number;
	int i;

	i = 0;
	number = (int)ft_atoi(argv[i]);
	stack_a = ft_dlstnew(number); ////////////
	while (i < (argc - 1))
	{
		i++;
		number = (int)ft_atoi(argv[i]);
		//printf("valor: %d\n",stack_a->next->data);
		ft_dlstadd_back(stack_a, ft_dlstnew(number));
	}
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
	if (argv[i][j] == '-')
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
	t_stack	stack_a;
	t_stack stack_b;

	if (argc < 2)
		return (0);
	//reset_flags;
	argc--;
	argv = &argv[1];
	if (argc == 1)
		argv = check_params(&argc, argv);
	check_args(argc, argv);
	/*
	printf("quantidade de argumentos: %d\n", argc);
	while (*argv != NULL) {
	printf("os argumentos: %s\n", *argv);
	*argv++;}
	*/
	init_stacks(&stack_a, &stack_b);
	init_stack_a(&stack_a, argc, argv);

	printf("os argumentos: %i\n", stack_a.data);
	printf("os argumentos: %i\n", stack_a.next->data);

	/*
	while (stack_a.next != NULL)
	{
		printf("os argumentos: %d\n", *stack_a->data);
		stack_a = stack_a->next;
	}
	*/

	return (0);
}
