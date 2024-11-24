/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:59:15 by racabrer          #+#    #+#             */
/*   Updated: 2024/10/11 16:54:46 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int n)
{
	size_t	counter;

	counter = 0;
	if (n <= 0)
	{
		counter = 1;
	}
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

static void	ft_fill_string(char *str, long n, size_t size)
{
	size_t	index;

	index = size;
	str[index] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[--index] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	num_digits;

	num_digits = ft_count_digits(n);
	str = malloc(sizeof(char) * (num_digits + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	ft_fill_string(str, n, num_digits);
	return (str);
}
