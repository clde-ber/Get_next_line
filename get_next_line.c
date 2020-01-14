#include "get_next_line.h"
#define BUFFER_SIZE 62

int		get_next_line(int fd, char **line)
{
	size_t i;
	size_t j;
	size_t k;
	static char buf[BUFFER_SIZE];

	i = 0;
	j = 0;
	k = 0;
	while (BUFFER_SIZE > 0 && read(fd, buf, BUFFER_SIZE) > 0)
	{
		while (i < BUFFER_SIZE)
		{
			i = ft_get_index(i, buf, BUFFER_SIZE);
			if (!(*line = malloc(sizeof(char) * (i + 1))))
				return (0);
				printf("%zu\n", i);
			while (j < i)
			{
				line[0][j] = ft_get_letter(k, line, buf);
				j++;
				k++;
			}
			line[0][j] = '\0';
			printf("%s\n", *line);
			return (buf[k] == '\n') ? 1 : 0;
		}
		j = 0;
	}
	return (-1);
}

