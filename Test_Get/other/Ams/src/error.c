
#include <minishell.h>

void	malloc_fail(void)
{
	ft_dprintf(2, "Fatal error: malloc error occurred\n");
	exit(1);
}

void	quotes_error(char q)
{
	ft_dprintf(2, "msh: unexpected EOF while looking for matching `%c'\n", q);
	exit(2);
}

void	syntax_error(void)
{
	ft_dprintf(2, "msh: syntax error near unexpected token\n");
	exit(2);
}
