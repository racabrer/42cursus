/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:14:37 by racabrer          #+#    #+#             */
/*   Updated: 2024/10/18 19:52:06 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	longitud1;
	size_t	longitud2;
	size_t	longitud_total;
	char	*resultado;

	if (s1 == NULL && s2 == NULL)
	{
		return (NULL);
	}
	longitud1 = ft_strlen(s1);
	longitud2 = ft_strlen(s2);
	longitud_total = longitud1 + longitud2 + 1;
	resultado = malloc(longitud_total);
	if (resultado == NULL)
	{
		return (NULL);
	}
	ft_strcpy(resultado, (char *)s1);
	ft_strcpy(resultado + longitud1, (char *)s2);
	return (resultado);
}
