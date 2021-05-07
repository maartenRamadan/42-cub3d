/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 16:51:22 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/21 11:27:42 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = malloc(sizeof(*str2) * (ft_strlen(s1) + 1));
	if (!str2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str2[i] = s1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
