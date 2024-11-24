/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:58:52 by racabrer          #+#    #+#             */
/*   Updated: 2024/11/24 20:12:19 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	char	*src;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s) + 1;
	src = malloc(len * sizeof(char));
	if (src == NULL)
		return (NULL);
	while (s[i])
	{
		src[i] = s[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}

int	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	if (!s)
		return (0);
	while (s[a] != '\0')
		++a;
	return (a);
}

int	ft_strchr(const char *s, int c)
{
	unsigned char	cc;
	int				i;

	i = 0;
	cc = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == cc)
			return (i);
		i++;
	}
	if (cc == s[i])
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		size_s1;
	int		size_s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	res = (char *)malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (j < size_s1)
		res[j++] = s1[i++];
	i = 0;
	while (i < size_s2)
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}
