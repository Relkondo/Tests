#include "checker.h"
#include "libft.h"
#include <strings.h>

void	free_mem(t_che *che)
{
	if (che->ar)
		free_ar(che->ar, ft_lstlen(che->la));
	free_stack(che->la);
	free(che);
	exit(0);
}

int		main(int argc, char **argv)
{
	int		la;
	t_che	*che;

	if (argc <= 1)
		return (0);
	che = (t_che *)ft_memalloc(sizeof(t_che));
	la = args(argc, argv, che);
	if (!la)
	{
		ERROR;
		if (che->ar)
			free_ar(che->ar, ft_lstlen(che->la));
		free(che);
		exit(0);
	}
	che->llen = ft_lstlen(che->la);
	if (che->llen >= 2 && che->llen <= 3)
	{
		sort_thre(che);
		free_mem(che);
	}
	if (sort_che(che->la, ascending))
		exit(0);
	sort(che, che->llen);
	free_mem(che);
}
