#include "get_next_line.h"
#define BUFFER_SIZE 62

int		get_next_line(int fd, char **line)
{
	size_t i;
	size_t j;
	size_t k;
	int		res;
	char buf[BUFFER_SIZE];
	static char *stock;

	i = 0;
	j = 0;
	k = 0;
	res = 0;
		if (BUFFER_SIZE > 0)
		{
			if (!stock)
			{
				res = 1;
				printf("premiereboucle\n");
				read(fd, buf, BUFFER_SIZE);
	//			printf("%d\n", res);
				i = ft_get_index(i, buf, BUFFER_SIZE);
	//			printf("%zu\n", i);
			if (!(line[0] = malloc(sizeof(char) * (i + 1))))
				return (0);
	//		printf("i : %zu\n", i);
			stock = (i < BUFFER_SIZE) ? ft_fill_stock(i, BUFFER_SIZE, &buf[i], BUFFER_SIZE - i) :
				ft_strdup("");
	//		printf("stock :%s\n", stock);
			while (j < i)
			{
				line[0][j] = ft_get_letter(k, line, buf);
				j++;
				k++;
			}
			line[0][j] = '\0';
			}
			if (stock[0] == '\0' || stock[0])
			{
				printf("*stock %c\n", *stock);
				if (res)
				{	printf("line[0] %s\n", line[0]);
					return (1);}
				printf("strlen stock %zu\n", ft_strlen(stock));
				if ((ft_strlen(stock) == 1 && *stock) || ft_strlen(stock) == BUFFER_SIZE - 1)
				{
					if (!(stock = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
						return (0);
					read(fd, stock, BUFFER_SIZE);
					stock[BUFFER_SIZE - 1] = '\0';
					printf("stock :%s\n", stock);
				}
	//			if (!(line[0] = malloc(sizeof(char) * (ft_strlen(stock) + 1))))
	//				return (0);
	//			printf("ft-strlenstock + 1 %zu\n", ft_strlen(stock) + 1);
					i = 0;
					while(stock[i] != '\n' && stock[i] != '\0')
					{
						buf[i] = stock[i];
						i++;
						printf("i : %zu\n", i);
					}
						if (stock[i] == '\n')
						{	printf("AAAAA");
							i++;
							stock = stock + i;
						}
				//		if (stock[i] == '\0')
					if (!(line[0] = malloc(sizeof(char) * (i + 1))))
						return (0);
					j = 0;
					while (buf[j] && ft_strlen(stock) != BUFFER_SIZE - 1 && j++ < i)
						line[0][j] = buf[j];
					line[0][j] = '\0';
					if (res == 0)
					line[0] = stock;
					printf("stock2 :%s\n", stock);
					printf("line[0] %s\n", line[0]);
					printf("res %d", res);
				//	ft_del_stock(stock);
					return(1);
			}
		}
	return (-1);
}
