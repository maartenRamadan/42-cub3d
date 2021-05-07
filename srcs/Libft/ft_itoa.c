/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 16:25:06 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/11 12:33:29 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_len(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup((const char *)"-2147483648"));
	len = count_len(n);
	str = malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
