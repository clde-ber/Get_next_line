#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_get_index(size_t i, char *buf, size_t BUFFER_SIZE);
char	ft_get_letter(size_t k, char **line,  char *buf);
size_t	ft_strlen(char *str);
size_t	ft_read(char **line, int fd, size_t BUFFER_SIZE);
char 	*ft_fill_stock(size_t i, size_t BUFFER_SIZE, char *buf, size_t len);
void	ft_del_stock(char *stock);
char	*ft_strdup(char *s1);

#endif
