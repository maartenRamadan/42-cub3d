/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 12:57:12 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/16 22:17:14 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cub_strdup(char *line, char **s)
{
	if (*s)
		return (ft_printf("Error\nDouble texture paths\n"));
	if (*line >= 'A' && *line <= 'Z' && *(line + 1) == ' ')
		line++;
	else
		line += 2;
	while (*line == ' ')
		line++;
	*s = ft_strdup(line);
	if (!s)
		return (ft_printf("Error\nMalloc fail\n"));
	return (0);
}

int		cub_atoi(char **line, char el, int c, t_vars *v)
{
	int		nb;

	nb = -1;
	while (**line == ' ')
		(*line)++;
	if (el != 'R' && c == 1 && (**line < '0' || **line > '9'))
		return (-1);
	if (el != 'R' && c > 1 && **line != ',')
		return (-1);
	if (el != 'R' && c > 1 && **line == ',')
		(*line)++;
	while (**line == ' ')
		(*line)++;
	while (**line && (**line >= '0' && **line <= '9'))
	{
		if (nb == -1)
			nb = 0;
		nb = nb * 10 + (**line - 48);
		(*line)++;
	}
	if ((el == 'R' && (v->res_h || (c == 2 && check_white_space_only(*line))))
	|| (el != 'R' && (c == 3 && check_white_space_only(*line))))
		return (-1);
	return (nb);
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

int		check_floor_color(t_vars *v, char **line)
{
	int r;
	int g;
	int b;

	if (v->f_color)
		return (ft_printf("Error\nDouble floor color\n"));
	(*line)++;
	r = cub_atoi(line, 'F', 1, v);
	g = cub_atoi(line, 'F', 2, v);
	b = cub_atoi(line, 'F', 3, v);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_printf("Error\nInvalid floor color\n"));
	v->f_color += b % 16 * (ft_recursive_power(16, 0));
	v->f_color += b / 16 * (ft_recursive_power(16, 1));
	v->f_color += g % 16 * (ft_recursive_power(16, 2));
	v->f_color += g / 16 * (ft_recursive_power(16, 3));
	v->f_color += r % 16 * (ft_recursive_power(16, 4));
	v->f_color += r / 16 * (ft_recursive_power(16, 5));
	return (0);
}

int		check_color(char *line, t_vars *v, char c)
{
	int r;
	int g;
	int b;

	if (c == 'F')
	{
		if (check_floor_color(v, &line))
			return (1);
	}
	if (c == 'C')
	{
		line++;
		r = cub_atoi(&line, 'C', 1, v);
		g = cub_atoi(&line, 'C', 2, v);
		b = cub_atoi(&line, 'C', 3, v);
		if (v->c_c || r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
			return (ft_printf("Error\nInvalid or double ceiling color\n"));
		v->c_c += b % 16 * (ft_recursive_power(16, 0));
		v->c_c += b / 16 * (ft_recursive_power(16, 1));
		v->c_c += g % 16 * (ft_recursive_power(16, 2));
		v->c_c += g / 16 * (ft_recursive_power(16, 3));
		v->c_c += r % 16 * (ft_recursive_power(16, 4));
		v->c_c += r / 16 * (ft_recursive_power(16, 5));
	}
	return (0);
}
