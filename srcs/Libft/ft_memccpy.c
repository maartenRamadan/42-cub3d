/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 09:54:24 by mramadan       #+#    #+#                */
/*   Updated: 2019/10/31 16:15:00 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	i = 0;
	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (0);
}
