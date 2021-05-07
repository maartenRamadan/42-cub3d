/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itohex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 11:22:02 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/15 21:03:11 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		itohex_len(int n, int len)
{
	if (n >= 16)
	{
		len = itohex_len(n / 16, len + 1);
		itohex_len(n % 16, len);
	}
	else
		len++;
	return (len);
}

char	hex_to_str(int n, char *s)
{
	int		abc;
	char	c;

	abc = 0;
	if (n <= 9)
		c = (48 + n);
	else if (n > 9)
	{
		while (n > 9)
		{
			n--;
			abc++;
		}
		c = (96 + abc);
	}
	return (c);
}

char	*itohex(int n)
{
	char	*s;
	int		len;

	len = 0;
	len = itohex_len(n, len);
	s = malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (n > 0)
	{
		len--;
		s[len] = hex_to_str(n % 16, s);
		n = n / 16;
	}
	return (s);
}
