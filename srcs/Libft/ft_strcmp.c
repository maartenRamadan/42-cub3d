/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 10:30:46 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/24 10:00:25 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (((int)((unsigned char)s1[i])) - ((int)((unsigned char)s2[i])));
}
