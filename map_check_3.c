/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check_3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Marty <Marty@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 12:48:59 by Marty         #+#    #+#                 */
/*   Updated: 2020/04/16 21:40:35 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_line(t_vars *v, int x, int y)
{
	while (x < v->cols)
	{
		v->array[y][x] = ' ';
		x++;
	}
	v->array[y][x] = '\0';
}

int		fill_array(t_vars *v, int *x, int y, int *i)
{
	char *orientations;
	char *allowed;

	orientations = "NESW";
	allowed = "012NE 	SW\n";
	while (v->map[*i] != '\0' && v->map[*i] != '\n')
	{
		if (!ft_strchr(allowed, v->map[*i]))
			return (ft_printf("Error\nUse of unallowed map character!\n"));
		else
			v->array[y][*x] = v->map[*i];
		if (ft_strchr(orientations, v->array[y][*x]))
		{
			if (v->or)
				return (ft_printf("Error\nMultiple starting points!\n"));
			v->or = v->array[y][*x];
			v->posx = *x + 0.5;
			v->posy = y + 0.5;
		}
		(*x)++;
		(*i)++;
	}
	return (0);
}

char	*cub_strjoin(char **s1, char **s2)
{
	char	*s3;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!*s1 || !*s2)
		return (0);
	s3 = malloc(ft_strlen(*s1) + ft_strlen(*s2) + 2);
	if (!s3)
		return (0);
	while ((*s1)[i] != '\0')
	{
		s3[i] = (*s1)[i];
		i++;
	}
	while ((*s2)[i2] != '\0')
	{
		s3[i] = (*s2)[i2];
		i++;
		i2++;
	}
	s3[i] = '\n';
	s3[i + 1] = '\0';
	return (s3);
}

int		check_white_space_only(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '	')
			return (1);
		line++;
	}
	return (0);
}
