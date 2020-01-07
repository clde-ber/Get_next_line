#define BUFFER_SIZE 1024

int		get_next_line(int fd, char **line)
{
	size_t tab_size;
	size_t len_line;
	int fd;
	char *buf;
	int boolean;

	tab_size = 0;
	len_line = 0;
	boolean = 0;
	if (fd < 0)
		return (0);
	while (read(fd, buf, BUFFER_SIZE))
	{
		len_line = read(fd, buf, BUFFER_SIZE);
		buf = malloc(sizeof(char) * (len_line + 1));
		line[tab_size] = ;
		tab_size++;
}
