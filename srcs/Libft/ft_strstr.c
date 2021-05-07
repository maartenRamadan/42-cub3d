/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 10:41:26 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/16 19:26:21 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char		*ptr;
	size_t		i;
	int			i2;

	i = 0;
	i2 = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	if (ft_strlen(haystack) == 0)
		return (NULL);
	while (haystack[i] != '\0')
	{
		while (haystack[i + i2] == needle[i2])
		{
			if (!needle[i2 + 1])
			{
				ptr = (char*)&haystack[i];
				return (ptr);
			}
			i2++;
		}
		i2 = 0;
		i++;
	}
	return (0);
}
