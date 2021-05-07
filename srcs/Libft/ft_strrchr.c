/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 18:12:24 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/21 10:29:25 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s)
	{
		if (*s == c)
			ret = (char *)s;
		s++;
	}
	if (ret)
		return (ret);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
