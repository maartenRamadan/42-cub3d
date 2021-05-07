/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:16:16 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/19 15:36:02 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	if (!alst)
		return ;
	temp = ft_lstlast(*alst);
	if (!temp)
		*alst = new;
	else
		temp->next = new;
}
