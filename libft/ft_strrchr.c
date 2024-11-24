/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:15:16 by racabrer          #+#    #+#             */
/*   Updated: 2024/10/14 22:40:32 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	cc;

	cc = (char)c;
	res = NULL;
	while (*s)
	{
		if (*s == cc)
		{
			res = (char *)s;
		}
		s++;
	}
	if (cc == '\0')
	{
		res = (char *)s;
	}
	return (res);
}
