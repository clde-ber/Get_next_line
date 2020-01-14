#include "get_next_line.h"
#define BUFFER_SIZE 62

int		get_next_line(int fd, char **line)
{
	size_t i;
	size_t j;
	size_t k;
	size_t res;
	static char buf[BUFFER_SIZE];

	i = 0;
	j = 0;
	k = 0;
	res = 0;
		while (i < BUFFER_SIZE)
		{
			if (!line[0])
			{
				printf("premiereboucle");
				res = read(fd, buf, BUFFER_SIZE);
				i = ft_get_index(i, buf, res);
				printf("longueur prise :%zu\n", BUFFER_SIZE - ft_strlen(&buf[i]));
			if (!(*line = malloc(sizeof(char) * (i + BUFFER_SIZE - ft_strlen(&buf[i])))))
				return (0);
			printf("taille restante : %zu\n",  ft_strlen(&buf[i]));
			printf("i : %zu\n", i);
			while (j < i)
			{
				line[0][j] = ft_get_letter(k, line, buf);
				j++;
				k++;
			}
			line[0][j] = '\0';
			printf("%s\n", *line);
			return (1);
			}
			else
			{
				printf("a");
				if (read(fd, buf, BUFFER_SIZE));
				{
					i = ft_strlen(buf) - ft_strlen(line);
					line[0] = ft_strjoin(line[0], &buf[i]);
					printf("%s\n", line[0]);
					return(1);
				}
				return (0);
			}
		}
	return (0);
}
