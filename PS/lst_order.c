#include "checker.h"

int		ascending(int a, int b)
{
	return (a <= b);
}

t_stack	*sort_che(t_stack *lst, int (*cmp)(int, int))
{
	t_stack	*tmp;

	tmp = lst;
	while (lst->next != 0)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			return (0);
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
