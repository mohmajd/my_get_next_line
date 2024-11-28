#include "get_next_line.h"

static int	ft_new(char *buffer)
{
	while (buffer && *buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

static char	*ft_read(int fd, char **rest)
{
	char	*temp;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	temp = ft_strjoin(*rest, buffer);
	*rest = temp;
	return (*rest);
}

static char	*ft_rest(char **rest)
{
	char	*line;

	if (*rest && ft_len(*rest) > 0)
	{
		line = ft_substr(*rest, 0, ft_len(*rest));
		free(*rest);
		*rest = NULL;
		return (line);
	}
	free(*rest);
	*rest = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*newline;
	char		*new_rest;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if ((!buffer || !ft_new(buffer)) && !ft_read(fd, &buffer))
			break ;
		newline = ft_strchr(buffer, '\n');
		if (newline)
		{
			count = newline - buffer + 1;
			line = ft_substr(buffer, 0, count);
			new_rest = ft_substr(buffer, count, BUFFER_SIZE);
			free(buffer);
			buffer = new_rest;
			return (line);
		}
		return (ft_rest(&buffer));
	}
	return (ft_rest(&buffer));
}

int main()
{
	int fd = open("file.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}