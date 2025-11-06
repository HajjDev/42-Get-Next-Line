/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 23:08:02 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/11/06 22:06:06 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *buffer)
{
	int		size;
	int		i;
	char	*line;

	if (!buffer || !*buffer)
		return (NULL);
	if (ft_find(buffer, '\n') == -1)
		size = ft_strlen(buffer);
	else
		size = ft_find(buffer, '\n') + 1;
	line = (char *)malloc((size + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < size)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clear_buffer(char *buffer)
{
	int		index;
	int		j;
	char	*new_buffer;

	index = ft_find(buffer, '\n');
	if (index == -1)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc((ft_strlen(buffer) - index) * sizeof(char) + 1);
	if (!new_buffer)
		return (NULL);
	index++;
	j = 0;
	while (buffer[index])
	{
		new_buffer[j] = buffer[index];
		index++;
		j++;
	}
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*ft_error(char *buffer)
{
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	char		*line;
	char		read_file[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (ft_find(buffer, '\n') == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, read_file, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_error(buffer));
		read_file[bytes_read] = '\0';
		temp = ft_strjoin(buffer, read_file);
		free(buffer);
		buffer = temp;
	}
	line = extract_line(buffer);
	buffer = clear_buffer(buffer);
	return (line);
}
