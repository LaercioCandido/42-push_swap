#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	double			total;
	unsigned int	i;
	int				sinal;

	total = 0;
	i = 0;
	sinal = 1;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sinal = (-1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + str[i] - '0';
		i++;
	}
	return (sinal * total);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int			count_numbers(int ac, char **av)
{
	int			i;
	int			j;
	int			tot;

	i = 1;
	tot = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] && av[i][j] == ' ')
				j++;
			if ((av[i][j] && ((ft_isdigit(av[i][j])) || (av[i][j] == '-'))))
				tot++;
			else
				return (0);
			while ((av[i][j] && ((ft_isdigit(av[i][j])) || (av[i][j] == '-'))))
				j++;
		}
		i++;
	}
	return (tot);
}

int main(int argc, char *argv[])
{
    int cont;
    int len;

    if (argc < 2)
        return (0);
    else
    {
        len = count_numbers(argc, argv);
        cont = 0;
        //tmp = malloc do tamanho de argc
        int tmp[5];
		argv = &argv[1];
        while (cont < (argc - 1))
        {
            tmp[cont] = ft_atoi(argv[cont]);
            cont++;
        }
	}
  return (0);
}

