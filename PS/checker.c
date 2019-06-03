#include "libft.h"
#include "checker.h"
#include <string.h>

int		main(int argc, char **argv)
{
	int		la;
	t_che	*che;

	if (argc <= 1)
		return (0);
	che = (t_che *)ft_memalloc(sizeof(t_che));
	che->llen = 0;
	la = args(argc, argv, che);
	if (!la)
	{
		ERROR;
		exit(0);
	}
	if (!read_instruction(che))
	{
		ERROR;
		exit(0);
	}
	if (!sort_che(che->la, ascending) || ft_lstlen(che->lb) > 0)
	{
		KO;
		exit(0);
	}
	OK;
	exit(1);
}
