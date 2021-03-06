
#include <minishell.h>

static size_t	ft_getbufsize(t_buf *buf)
{
	size_t	ret;

	ret = 0;
	while (buf)
	{
		ret += buf->len;
		buf = buf->next;
	}
	return (ret);
}

char			*ft_buftostr(t_buf *buf_head)
{
	size_t	b_size;
	t_buf	*tmp;
	char	*str;

	b_size = ft_getbufsize(buf_head);
	if (!buf_head)
		return (ft_strdup(""));
	if (!(str = ft_memalloc(sizeof(char) * (b_size + 1))))
		malloc_fail();
	while (buf_head)
	{
		tmp = buf_head->next;
		ft_strncat(str, buf_head->str, buf_head->len);
		free(buf_head);
		buf_head = tmp;
	}
	return (str);
}

void			ft_putchar_mshbuf(t_buf **buf, char c)
{
	if (!buf || !*buf)
		return ;
	if ((*buf)->len == BUFF_SIZE)
	{
		if (!((*buf)->next = ft_memalloc(sizeof(t_buf))))
			malloc_fail();
		(*buf)->next->id = (*buf)->id + 1;
		*buf = (*buf)->next;
	}
	(*buf)->str[(*buf)->len++] = c;
}

void			ft_putstr_mshbuf(t_buf **buf, char *str, ssize_t len)
{
	if (!str || !buf || !*buf)
		return ;
	if (len == -1)
		while (*str)
			ft_putchar_mshbuf(buf, *str++);
	else
		while (len && *buf)
		{
			ft_putchar_mshbuf(buf, *str++);
			len--;
		}
}

void			*ft_free_mshbuf(t_buf *buf)
{
	t_buf	*tmp;

	while (buf)
	{
		tmp = buf->next;
		free(buf);
		buf = tmp;
	}
	return (NULL);
}
