#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int             data;
    int             index;
    struct  s_stack *next;
    struct  s_tack  *previous;
}               t_stack;

int			count_numbers(int ac, char **av);

#endif