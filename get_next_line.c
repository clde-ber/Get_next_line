#include "get_next_line.h"

static char		*ft_read_a_join(size_t i, char *buf, char **line)
{
	buf[i] = '\0';
	line[0] = ft_strjoin(line[0], buf);
	return (line[0]);
}

int				get_next_line(int fd, char **line)
{
	ssize_t		i;
	char		buf[BUFFER_SIZE + 1];
	static char *left;

	buf[0] = '\0';
	left = (!left) ? ft_create_a_clear_left(left, BUFFER_SIZE) : left;
	line[0] = ft_strjoin(left, "");
	ft_create_a_clear_left(left, BUFFER_SIZE);
	if (find_n(line[0], ft_strlen(line[0])) != -1)
	{
		line[0][find_n(line[0], ft_strlen(line[0]))] = '\0';
		return (1);
	}
	while (find_n(buf, BUFFER_SIZE) == -1 &&
	(i = read(fd, buf, BUFFER_SIZE)) > 0)
		line[0] = ft_read_a_join(i, buf, line);
	line[0] = (i == 0) ? line[0] : ft_strjoin(line[0], buf);
	if (find_n(line[0], ft_strlen(line[0])) != -1)
	{
		line[0][find_n(line[0], ft_strlen(line[0]))] = '\0';
		ft_memmove(left, buf + find_n(buf, BUFFER_SIZE) + 1,
			ft_strlen(buf) + 1);
		return (1);
	}
	return (fd < 0 || read(fd, buf, 0) < 0 || BUFFER_SIZE == 0) ? -1 : 0;
}
