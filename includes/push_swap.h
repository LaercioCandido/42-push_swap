#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_stack
{
    int             data;
    int             index;
    struct  s_stack *next;
    struct  s_stack  *previous;
}               t_stack;

void	return_error(void);
static char	**check_params(int *argc, char **argv);
static void	check_type_arg(char **argv, int i);
static void	check_args(int argc, char **argv);
static void init_stacks(t_stack *stack_a, t_stack *stack_b);
void init_stack_a(t_stack *stack_a, int argc, char **argv);

t_stack	*ft_dlstlast(t_stack *lst);
t_stack	*ft_dlstnew(int data);
void	ft_dlstadd_back(t_stack *lst, t_stack *new);


/*
double	ft_atoi(const char *nptr);
int	    ft_isdigit(int c);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *frase);
*/



#endif