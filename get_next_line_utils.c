#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!(ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_get_index(size_t i, char *buf, size_t BUFFER_SIZE)
{
	size_t j;

	j = 0;
	while (j < BUFFER_SIZE)
	{
		if (buf[j] == '\n')
			break;
		j++;
	}
	return (j);
}

char	*ft_fill_stock(size_t i, size_t BUFFER_SIZE, char *buf, size_t len)
{
	size_t j;
	char *stock;

	j = 0;
	if (!(stock = malloc(sizeof(char) * (BUFFER_SIZE - i + 1))))
		return (0);
	while (j < len)
	{
		stock[j] = buf[j];
		j++;
	}
	stock[j] = '\0';
	return (stock);
}

void	ft_del_stock(char *stock)
{
	size_t i;

	i = 0;
	while (stock[i])
	{
		stock[i] = '\0';
		i++;
	}
}

char	ft_get_letter(size_t k, char **line,  char *buf)
{
	if (buf[k] == '\n')
		return ('\0');
	if (buf[k] != '\n')
		return (buf[k]);
	return ('\0');
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str && *str != (char)c)
		str++;
	return (*str == c ? str : NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;
	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || s1[0] == '\0')
		return (ft_strdup(s2));
	if (!s2 || s2[0] == '\0')
		return (ft_strdup(s1));
	if (!(ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
