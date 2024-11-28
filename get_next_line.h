#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <libc.h>

char	*ft_strcpy(char *dst, char *src);
int		ft_len(char *s);
char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif

#ifndef BUFFER_SIZE
#define  BUFFER_SIZE 32
#endif