#include "get_next_line.h"
#define BUFFER_SIZE 1000

int		get_next_line(int fd, char **line)
{
	size_t i;
	size_t j;
	size_t k;
	int		res;
	char buf[BUFFER_SIZE];
	char end[BUFFER_SIZE];
	static char *stock;

	i = 0;
	j = 1;
	k = 0;
	res = 0;
		if (BUFFER_SIZE > 0)
		{
				if (!stock || ft_strlen(stock) == BUFFER_SIZE)
				{	printf("aaaaa");
					if (!stock || stock[0] == '\0')
					{if (!(stock = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
						return (0);
					read(fd, stock, BUFFER_SIZE);}
					k = ft_get_index(j, stock, BUFFER_SIZE);
					printf("j %zu\n", j);
					printf("k = %zu\n", k);
					if (stock[0]){
						line[0] = ft_strdup("");
						line[0] = ft_strjoin(line[0], stock);}
				while (k == BUFFER_SIZE * j)
				{
					read(fd, buf, BUFFER_SIZE);
					printf("k ! = %zu\n", k);
					line[0] = ft_strjoin(line[0], buf);
					k = ft_get_index(++j, line[0], BUFFER_SIZE);
					printf("j %zu\n", j);
					printf("k !! = %zu\n", k);
					printf("BUF = %s\n", buf);
					printf("ft_strlen(line[0] %zu\n", ft_strlen(line[0]));
					printf("line %s\n", line[0]);
					if (k < ft_strlen(line[0]))
					{
						free(stock);
						stock = ft_strdup(&line[0][k + 1]);
						printf("STOCK %s\n", stock);
						while (k + i <= ft_strlen(line[0]))
						line[0][k + i++] = '\0';
						printf("KKKKKKKKK %zu\n", k);}
					printf("line[0] boucle petit BUFFER %s\n", line[0]);
					return (1);}
				}
				//	stock[BUFFER_SIZE - 1] = '\0';
				//	printf("stock :%s\n", stock);
				else
				{
			//	k = ft_get_index(k, buf, BUFFER_SIZE) + 1;
		//		if (i < BUFFER_SIZE - 1)
			//		 ft_fill_stock(i, BUFFER_SIZE, &buf[i], BUFFER_SIZE - i);
	//			if (!(line[0] = malloc(sizeof(char) * (ft_strlen(stock) + 1))))
	//				return (0);
	//			printf("ft-strlenstock + 1 %zu\n", ft_strlen(stock) + 1);
					i = 0;
					while(stock[i] != '\n' && stock[i] != '\0')
					{
						buf[i] = stock[i];
						i++;
			//			printf("i : %zu\n", i);
					}
					buf[i] = '\0';
					printf("BUF = %s\n", buf);
						if (stock[i] == '\n')
						{	printf("AAAAA");
							i++;
							stock = stock + i;
						}
						if (stock[i] == '\0' && i != 0)
						{
						//	res = read(fd, end, BUFFER_SIZE);
						//	while (res < BUFFER_SIZE)
						//		end[res++] = '\0';
						//		printf("stock fin %s\n", stock);
							line[0] = ft_strdup(stock);
							printf("line[0] boucle finale %s\n", line[0]);
							ft_del_stock(stock);
							return (0);
						}
				//	if (!(line[0] = malloc(sizeof(char) * i)))
				//		return (0);
					j = 0;
					line[0] = ft_strdup(buf);
			//		while (buf[j] && ft_strlen(stock) != BUFFER_SIZE - 1 && j++ < i)
			//			line[0][j] = buf[j];
			//		line[0][j] = '\0';
			//		if (res == 0)
			//		line[0] = stock;
					printf("stock2 :%s\n", stock);
					printf("line[0] %s\n line[0]", line[0]);
					printf("res %d", res);
				//	ft_del_stock(stock);
					return(1);
				}
			}
	//	}
	return (-1);
}
