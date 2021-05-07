/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 13:10:45 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/20 16:23:26 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_write_s2(char *s1, int start, int len)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char*)malloc(len + 1);
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		start;
	int		len;

	len = 0;
	start = 0;
	s2 = NULL;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (start > len)
		return (ft_calloc(1, 1));
	while (s1[len - 1] && ft_strchr(set, s1[len - 1]))
		len--;
	if (len != 0)
		len = len - start;
	if (len < 0)
		return (NULL);
	s2 = ft_write_s2((char*)s1, start, len);
	return (s2);
}
