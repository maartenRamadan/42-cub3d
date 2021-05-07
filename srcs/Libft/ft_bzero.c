/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:41:14 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/19 17:13:21 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*tmp;

	tmp = (char*)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
}
