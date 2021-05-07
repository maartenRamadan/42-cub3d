/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 10:30:46 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/21 11:21:44 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < (n - 1))
		i++;
	return (((int)((unsigned char)s1[i])) - ((int)((unsigned char)s2[i])));
}
