/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:36:03 by racabrer          #+#    #+#             */
/*   Updated: 2024/11/24 20:06:20 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_buffer(char *buff)
{
	char	*new_buff;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	len = ft_strlen(buff) - i;
	new_buff = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_buff)
		return (NULL);
	i++;
	while (buff[i])
		new_buff[j++] = buff[i++];
	new_buff[j] = '\0';
	free(buff);
	return (new_buff);
}

char	*ft_free(char *buff, char *aux)
{
	char	*line;

	if (ft_strlen(aux) == 0)
		return (NULL);
	line = ft_strjoin(buff, aux);
	free(buff);
	return (line);
}

char	*ft_set_line(char *line_buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (line_buffer[j] && line_buffer[j] != '\n')
	{
		line[j] = line_buffer[j];
		j++;
	}
	if (line_buffer[i] && line_buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read_buff(char *buff, int fd)
{
	char	*aux;
	int		byte;

	aux = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (NULL);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, aux, BUFFER_SIZE);
		aux[byte] = '\0';
		if (byte <= 0)
		{
			free(aux);
			return (buff);
		}
		buff = ft_free(buff, aux);
		if (ft_strchr(buff, '\n') != -1)
			break ;
	}
	free(aux);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buff == NULL || ft_strlen(buff) == 0)
	{
		buff = ft_read_buff(buff, fd);
		if (!buff)
			return (free(buff), NULL);
	}
	if (buff == NULL)
		return (NULL);
	line = ft_set_line(buff);
	if (!line)
		return (NULL);
	if (ft_strchr(buff, '\n') == -1)
	{
		free(buff);
		buff = NULL;
		return (line);
	}
	buff = ft_trim_buffer(buff);
	return (line);
}
