/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:30:45 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/24 15:05:38 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		tmp[i] = c;
		i++;
	}
	return (b);
}
