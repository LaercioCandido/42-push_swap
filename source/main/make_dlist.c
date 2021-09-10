#include "../../includes/push_swap.h"

int	ft_dlstsize(t_dlist *lst)
{
	t_dlist	*aux;
	int		size;

	aux = lst;
	size = 0;
	while (aux != NULL)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}

t_dlist	*ft_dlstnew(int data)
{
	t_dlist	*pointer;

	pointer = (t_dlist *)malloc(sizeof(t_dlist));
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
