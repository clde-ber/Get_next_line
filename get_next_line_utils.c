#include "get_next_line.h"

int		find_n(char *buf, size_t size)
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

char	*ft_create_a_clear_left(char *left, size_t size)
{
	int k;

	if (left)
	{
		k = find_n(left, size);
		if (k != -1)
			ft_memmove(left, left + k + 1, ft_strlen(left + k) + 1);
		else
			left[0] = '\0';
		return (left);
	}
	else
	{
		if (!(left = malloc(sizeof(char) * (size + 1))))
			return (0);
		left[0] = '\0';
		return (left);
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;
	size_t			i;

	i = 0;
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
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*join_a_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	dont_free_left;
	char	*ptr;

	i = -1;
	j = -1;
	dont_free_left = 0;
	if (s2[0] == '\0')
		dont_free_left = 1;
	if (!s1 && !s2)
		return (0);
	if (!(ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[++j])
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	if (dont_free_left == 0)
		free(s1);
	return (ptr);
}
