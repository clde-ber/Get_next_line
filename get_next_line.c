#include "get_next_line.h"
#define BUFFER_SIZE 3000

static char 	buf[BUFFER_SIZE];
static size_t	tab_size;

int		get_next_line(int fd, char **line)
{
	size_t i;
	size_t j;
	int res;
	char *buf;

	tab_size = 0;
	i = 0;
	j = 0;
	res = 0;
	buf = 0;
	while (read(fd, buf, BUFFER_SIZE))
	{
		while (buf[i] != '\n' || buf[i] != '\0')
			i++;
		while (i < BUFFER_SIZE)
			ft_get_line(i, buf, BUFFER_SIZE);
		if (!(line[tab_size++] = malloc(sizeof(char) * (i + 1))))
			return (0);
		i = 0;
		while (buf[i++] != '\n')
			line[tab_size][j++] = buf[i];
		line[tab_size][j + 1] = '\0';
		return = (buf[i] = '\0') ? 0 : 1;
		i = 0;
	}
	return (-1);
}
