#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
char		*join_a_free(char *s1, char *s2);
size_t		ft_strlen(char *str);
int			find_n(char *buf, size_t size);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_create_a_clear_left(char *left, size_t size);

#endif
