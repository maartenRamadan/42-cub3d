/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 11:25:26 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/19 17:25:25 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = NULL;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			ptr = (unsigned char *)&s[i];
			return (ptr);
		}
		i++;
	}
	return (ptr);
}
