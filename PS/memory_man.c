#include "libft.h"
#include "checker.h"
#include <stdlib.h>

void	bzero_array(char **ar, int n)
{
	int line;

	line = 0;
	while (line < n)
	{
		ft_bzero(ar[line], n);
		line++;
	}
}

void	free_ar(char **ar, int n)
{
	int e;

	e = 0;
	while (e < n)
	{
		free(ar[e]);
		e++;
	}
}

void	free_stack(t_stack *stack)
{
	if (stack->next)
		free_stack(stack->next);
	free(stack);
}
