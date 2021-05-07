/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 14:06:07 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/16 16:25:13 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		*convert_str(const char *str, int strlen, int *str2)
{
	int i;

	i = 0;
	str2 = (int*)malloc(sizeof(*str2) * strlen + 1);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str2[i] = str[i] - 'W';
		else if (str[i] >= 'A' && str[i] <= 'F')
			str2[i] = str[i] - '7';
		else if (str[i] >= '0' && str[i] <= '9')
			str2[i] = str[i] - '0';
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

int		ft_recursive_power(int nb, int power)
{
	if (nb == 1 || power == 0)
		return (1);
	else if (nb == 0 || power < 0)
		return (0);
	else
	{
		nb = nb * ft_recursive_power(nb, power - 1);
		return (nb);
	}
}

int		ft_atoi_base(const char *str, int str_base)
{
	int strlen;
	int *str2;
	int i;
	int result;
	int fact;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		strlen++;
		i++;
	}
	str2 = convert_str(str, strlen, str2);
	i = 0;
	while (strlen > 0)
	{
		result = result + (ft_recursive_power(str_base, i) * str2[strlen - 1]);
		i++;
		strlen--;
	}
	free(str2);
	return (result);
}
