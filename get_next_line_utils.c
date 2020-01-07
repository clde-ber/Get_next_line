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

char	*ft_extract_str(const char *s, char c)
{
		size_t i;

		i = 0;
		while (s[i])
		{
			if (s[i] == '\n')
				return (
			i++;
