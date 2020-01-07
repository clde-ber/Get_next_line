#define BUFFER_SIZE 1024

int		get_next_line(int fd, char **line)
{
	size_t size;
	int fd;
	char *buf;
	int boolean;
	int reading;

	size = 0;
	boolean = 0;
	if (fd < 0)
		return (0);
	reading = read(fd, buf, BUFFER_SIZE);
	while (reading)
	{

}
