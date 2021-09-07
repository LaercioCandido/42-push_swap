#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_dlist
{
	int				data;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}					t_dlist;

typedef struct s_stack
{
	t_dlist			*a;
	t_dlist			*b;
	int				largest_data;
}					t_stack;

void	return_error(void);
void	init_stacks(t_stack *stack);
void	init_stack_a(t_dlist **stack_a, int argc, int *normalized);
int		*normalized_by_index(char **argv, int size);
void	quick_sort(int *array, int start, int end);
void	largest_data(t_stack *stack);
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlstnew(int data);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
int		ft_dlstsize(t_dlist *lst);
void	swap_nodes(t_dlist *first, t_dlist *second);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_both(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_both(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_both(t_stack *stack);
void	push_a(t_stack	*stack);
void	push_b(t_stack	*stack);
void	sort_stack(t_stack *stack, int argc);
int		stack_ordered(t_stack *stack, int size);
void	sort_three_nodes(t_stack *stack);
void	sort_five_nodes(t_stack *stack, int qtt_nodes);
void	radix_sort(t_stack *stack);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t count, size_t size);
double	ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *frase);

#endif
