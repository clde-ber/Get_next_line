#include "get_next_line.h"

int	ft_find_n(char *buf, size_t size)
{
	size_t i;

	i = 0;
	while (i < size && buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_clear_left(char *left, size_t size)
{
	int k;

	k = ft_find_n(left, size);
	if (k != -1)
	{
		ft_memmove(left, left + k + 1, ft_strlen(left));
		left[ft_strlen(left)] = '\0';
	}
	else
		left[0] = '\0';
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (!dst && !src)
		return (NULL);
	if (src <= dst)
	{
		tmp_dst = (unsigned char *)dst;
		tmp_src = (unsigned char *)src;
		while (len--)
			tmp_dst[len] = tmp_src[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

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

size_t	ft_get_index(size_t j, char *buf, size_t BUFFER_SIZE)
{
	size_t i;

	i = 0;
	while (i < BUFFER_SIZE * j)
	{
		if (buf[i] == '\n')
			break;
		i++;
	}
	return (i);
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
