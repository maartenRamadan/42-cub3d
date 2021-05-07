/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 11:53:49 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/21 11:37:16 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *node;

	node = (t_list*)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
