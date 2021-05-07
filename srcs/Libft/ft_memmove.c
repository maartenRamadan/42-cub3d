/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 11:08:58 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/19 17:19:56 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	return (dst);
}
