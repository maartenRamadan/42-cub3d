/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 11:22:02 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/15 21:02:16 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_puthex_fd(int n, int fd)
{
	int i;

	i = 0;
	if (n >= 16)
	{
		ft_puthex_fd(n / 16, fd);
		ft_puthex_fd(n % 16, fd);
	}
	else if (n <= 9)
		ft_puthex_fd(48 + n, fd);
	else if (n > 9)
	{
		while (n > 9)
		{
			n--;
			i++;
		}
		ft_putchar_fd(96 + i, fd);
	}
}
