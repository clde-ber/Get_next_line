#define BUFFER_SIZE 1024

int		get_next_line(int fd, char **line)
{
	int fd;
	char *buf;

	if (fd < 0)
		return (0);
	while (read(fd, buf, BUFFER_SIZE))
	{
		line =
		if (read(fd, buf, BUFFER_SIZE) == 0)
			break;
	}
}
