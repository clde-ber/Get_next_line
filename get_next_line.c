#include "get_next_line.h"
#define BUFFER_SIZE 100

int		get_next_line(int fd, char **line)
{
	size_t i;
	size_t j;
	size_t k;
	static char buf[BUFFER_SIZE];

	i = 0;
	j = 0;
	k = 0;
	while (BUFFER_SIZE > 0 && read(fd, buf, BUFFER_SIZE) >= 0)
	{
		if (i < BUFFER_SIZE)
		{
			if (buf[i + 1] != '\n')
			line[0] = ft_strdup(&buf[i]);i
			i = ft_get_index(i, buf, BUFFER_SIZE);
			if (!(*line = malloc(sizeof(char) * (i + 1))))
				return (0);
			printf("%zu\n", i);
			while (j <= i)
			{
				line[0][j] = ft_get_letter(k, line, buf);
				j++;
				k++;
			}
			printf("%s\n", *line);
			return (buf[j] == '\n') ? 1 : 0;
		}
		j = 0;
	}
	return (-1);
}
