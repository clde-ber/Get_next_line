#include "get_next_line.h"
#define BUFFER_SIZE 1024

static int	fd;
static char	*buf;

int		get_next_line(int fd, char **line)
{
	size_t tab_size;
	size_t len_line;
	int boolean;
	int res;

	tab_size = 0;
	len_line = 0;
	boolean = 0;
	res = 0;
	if (fd < 0)
		return (-1);
	while (read(fd, line[tab_size], BUFFER_SIZE))
	{
		if (boolean == 0)
			line[tab_size] = malloc(sizeof(char) * 1024);
		else
			line[tab_size] = malloc(sizeof(char) * len_line);
		len_line = read(fd, line[tab_size], BUFFER_SIZE);
		if (boolean)
			line[tab_size] = ft_strrchr(line[tab_size], '\n');
		boolean = 1;
		res = 1;
		tab_size++;
	}
	return (res);
}
