#include "get_next_line.h"
#define BUFFER_SIZE 3000

static char buf[BUFFER_SIZE];

int		get_next_line(int fd, char **line)
{
	size_t tab_size;
	size_t i;
	int res;

	tab_size = 0;
	i = 0;
	res = 0;
//	while (i < BUFFER_SIZE - 1)
//			buf[i++] = '\0';
//	printf("buf au depart = %s\n", buf);
	if (fd < 0)
		return (-1);
	i = 0;
	while (read(fd, buf, ft_set_size(*buf)))
	{
		printf("buffer %s\n", buf);
		printf("i %zu\n", i);
		if (!(line[tab_size] = malloc(sizeof(char) * i)))
			return (0);
		line[tab_size] = buf;
		res = 1;
		line[tab_size][++i] = '\0';
		printf("%s\n", line[tab_size]);
		tab_size++;
		i = 0;
	}
	line[tab_size] = 0;
	res = (res = 1) ? 0 : 1;
	return (res);
}#include "get_next_line.h"
#define BUFFER_SIZE 3000

static char buf[BUFFER_SIZE];

int		get_next_line(int fd, char **line)
{
	size_t tab_size;
	size_t i;
	int res;

	tab_size = 0;
	i = 0;
	res = 0;
//	while (i < BUFFER_SIZE - 1)
//			buf[i++] = '\0';
//	printf("buf au depart = %s\n", buf);
	if (fd < 0)
		return (-1);
	i = 0;
	while (read(fd, buf, ft_set_size(*buf)))
	{
		printf("buffer %s\n", buf);
		printf("i %zu\n", i);
		if (!(line[tab_size] = malloc(sizeof(char) * i)))
			return (0);
		line[tab_size] = buf;
		res = 1;
		line[tab_size][++i] = '\0';
		printf("%s\n", line[tab_size]);
		tab_size++;
		i = 0;
	}
	line[tab_size] = 0;
	res = (res = 1) ? 0 : 1;
	return (res);
}
