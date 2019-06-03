#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 1

typedef struct	s_list
{
	char		*ovr;
	char		*hold;
	int			fd;
}				t_ins;

int				get_next_line(const int fd, char **line);

#endif
