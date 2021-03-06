#include "checker.h"
#include "libft.h"
#include <strings.h>

int		find_next(t_che *che, int len, int range)
{
	t_stack *tmp;
	int		count;

	count = 0;
	tmp = che->la;
	while (tmp)
	{
		if (tmp->norm >= (len - range))
		{
			if (count >= len / 2)
				return (0);
		}
		count++;
		tmp = tmp->next;
	}
	return (1);
}

int		find_spec_next(t_che *che, int len, int num)
{
	t_stack *tmp;
	int		count;

	count = 0;
	tmp = che->lb;
	while (tmp != NULL)
	{
		if (tmp->norm == num)
		{
			if (count > (len / 2))
				return (0);
			else
				return (1);
		}
		count++;
		tmp = tmp->next;
	}
	return (1);
}

int		get_chunk(t_che *che, int llen)
{
	int slen;

	slen = ft_lstlen(che->lb);
	while (ft_lstlen(che->lb) - slen <= (llen / 5))
	{
		if (che->la->norm >= (llen - (llen / 5)))
		{
			PB;
			push_ab(&che->la, &che->lb);
		}
		else
		{
			if (find_next(che, llen, (llen / 5)) == 1)
			{
				while (!(che->la->norm >= (llen - (llen / 5))))
				{
					RA
					rotate_ab(&che->la);
				}
			}
			else
			{
				while (!(che->la->norm >= (llen - (llen / 5))))
				{
					RRA;
					revrot_ab(&che->la);
				}
			}
		}
	}
	return (1);
}

int		find_hi(t_che *che)
{
	t_stack *tmp;
	int		ret;

	ret = 0;
	tmp = che->lb;
	while (che->lb)
	{
		if (che->lb->norm > ret)
		{
			ret = che->lb->norm;
		}
		che->lb = che->lb->next;
	}
	che->lb = tmp;
	return (ret);
}

int		back2a(t_che *che)
{
	int n;

	n = find_hi(che);
	while (ft_lstlen(che->lb) > 0)
	{
		if (che->lb->norm == n)
		{
			PA;
			push_ab(&che->lb, &che->la);
			n--;
		}
		else if (find_spec_next(che, ft_lstlen(che->lb), n) == 0)
		{
			while (che->lb->norm != n)
			{
				RRB;
				revrot_ab(&che->lb);
			}
		}
		else
		{
			while (che->lb->norm != n)
			{
				RB;
				rotate_ab(&che->lb);
			}
		}
	}
	return (1);
}
