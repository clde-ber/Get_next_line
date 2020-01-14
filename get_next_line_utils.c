#include "get_next_line.h"

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
	while (buf[j] != '\n')
		j++;
	return (j);
}

char	ft_get_letter(size_t k, char **line,  char *buf)
{
	if (buf[k] == '\n')
		return ('\0');
	if (buf[k] != '\n')
		return (buf[k]);
	return ('\0');
}

size_t	ft_read(char **line, int fd, size_t BUFFER_SIZE)
{
	size_t i;
	char c[1];

	i = 0;
	while (c[0] != '\n')
	{
//		if (c[0] == '\0')
//			return (0);
		if (!((line[0][i] = malloc(sizeof(char)))))
			return (0);
		read(fd, &c, 1);
		if (c[0] == '\n')
			break;
		line[0][i] = c[0];
		i++;
	}
//	if (!(line[0][i] = malloc(sizeof(char))))
//		return (0);
	line[0][i] = '\0';
	while (c[0] == '\n' || c[0] == '\0')
		read(fd, &c, 1);
	printf("%s\n", *line);
	printf("a");
	return (1);
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

/*char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (ft_strdup(""));
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
}*/
