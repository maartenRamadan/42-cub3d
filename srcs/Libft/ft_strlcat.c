/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:13:18 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/21 10:18:09 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	ret;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (dstsize <= dstlen)
		ret = srclen + dstsize;
	else
		ret = dstlen + srclen;
	srclen = 0;
	while (dst != src && dstlen < (dstsize - 1) && src[srclen] != '\0')
	{
		dst[dstlen] = src[srclen];
		dstlen++;
		srclen++;
	}
	if (dstlen < dstsize)
		dst[dstlen] = '\0';
	return (ret);
}
