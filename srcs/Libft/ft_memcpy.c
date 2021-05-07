/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:33:40 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/07 12:34:23 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst1;
	char	*src1;
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (dst);
	dst1 = (char*)dst;
	src1 = (char*)src;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
