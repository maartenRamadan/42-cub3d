/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 10:09:40 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/25 09:35:43 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	int				i;
	int				len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	s2 = malloc(sizeof(*s2) * len + 1);
	if (!s2)
		return (NULL);
	while (s[i] != '\0')
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
