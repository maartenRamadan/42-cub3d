/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 13:52:10 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/24 15:04:36 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static long int	ft_conv(const char *str, int i, unsigned long int out, int in)
{
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if ((out >= 922337203685477580 && (str[i] - '0') > 7) && in == 1)
			return (-1);
		else if ((out >= 922337203685477580 && (str[i] - '0') > 8) && in == -1)
			return (0);
		out = out * 10 + (str[i] - '0');
		i++;
	}
	return (out);
}

int				ft_atoi(const char *str)
{
	unsigned long int	out;
	int					in;
	int					i;

	out = 0;
	i = 0;
	in = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		in = -1;
		i++;
	}
	out = ft_conv(str, i, out, in);
	return (in * out);
}
