#include "get_next_line.h"
#define BUFFER_SIZE 0

int		get_next_line(int fd, char **line)
{
	size_t i;
	char buf[BUFFER_SIZE + 1];
	static char *left;

	i = 0;
	buf[0] = '\0';
	left = (!left) ? ft_create_left(left, BUFFER_SIZE) : left;
	line[0] = ft_strdup(left);
	ft_clear_left(left, BUFFER_SIZE);
	if (ft_find_n(line[0], ft_strlen(line[0])) != -1)
	{
		line[0][ft_find_n(line[0], ft_strlen(line[0]))] = '\0';
		printf("%s\n", line[0]);
		return (1);
	}
	while (ft_find_n(buf, BUFFER_SIZE) == -1 && (i = read(fd, buf, BUFFER_SIZE)))
		line[0] = ft_strjoin(line[0], buf);
	line[0] = (i == 0) ? ft_strjoin(line[0], buf) : line[0];
	if (ft_find_n(line[0], ft_strlen(line[0])) != -1)
	{
		line[0][ft_find_n(line[0], ft_strlen(line[0]))] = '\0';
		ft_memcpy(left, buf + ft_find_n(buf, BUFFER_SIZE) + 1, ft_strlen(buf) + 1);
		printf("%s\n", line[0]);
		return (1);
	}
	return (fd < 0 || left == NULL || BUFFER_SIZE == 0) ? -1 : 0;
}
