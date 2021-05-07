/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:02:17 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/20 16:36:38 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (0);
	s3 = (char*)malloc(sizeof(*s3) * (ft_strlen(s1) +
	ft_strlen(s2) + 1));
	if (!s3)
		return (0);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		s3[i] = s2[i2];
		i++;
		i2++;
	}
	s3[i] = '\0';
	return (s3);
}
