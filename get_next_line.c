/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:38:49 by mohmajdo          #+#    #+#             */
/*   Updated: 2024/12/03 05:55:32 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(int fd, char *line)
{
	char	*buffer;
	char	*tmp;
	int		count;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	count = 1;
	while (!ft_strchr(line, '\n') && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[count] = '\0';
		tmp = ft_strjoin(line, buffer);
		if (!line)
			return (free (line), NULL);
	}
	free (line);
	line = tmp;
	return (line);
}

static char	*ft_new_line(char *line)
{
	char	*str;
	char	*newline;

	newline = ft_strchr(line, '\n');
	if (!newline)
		str = malloc(newline - line + 1);
	else
		str = malloc(ft_strlen(line + 1));
	if (!str)
		return (NULL);
	if (newline)
		ft_strncpy(str, line, newline - line + 1);
	else
		ft_strncpy(str, line, ft_strlen(line) + 1);
	return (free (line), str);
}

static char	*ft_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		str = (char *)malloc(i + 2);
	else
		str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (i < j)
	{
		str[j] = line[j];
		j++;
	}
	if (line [i] == '\n')
		str[i + 1] = '\n';
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*newline;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_get_line(fd, line);
	if (!line)
		return (NULL);
	buffer = ft_line(line);
	newline = ft_new_line(line);
	free (line);
	line = newline;
	return (buffer);
}

