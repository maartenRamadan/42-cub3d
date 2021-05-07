/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check_1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 12:56:41 by mramadan       #+#    #+#                */
/*   Updated: 2020/03/12 11:33:27 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		process_map(char **line, t_vars *v)
{
	char *str;
	int i;

	i = 0;
	v->e.rows++;
	v->e.cols = ft_strlen(*line) / 2;
	str = malloc(v->e.cols + 2);
	while (**line)
	{
		if (**line == ' ')
			(*line)++;
		if (!ft_strchr(v->e.allowed, **line))
			return (1);
		else
		{
			str[i] = **line;
			(*line)++;
			i++;
		}
	}
	str[i] = '\n';
	str[i + 1] = '\0';
	v->e.map = cub_strjoin(&v->e.map, &str);
	if (!v->e.map)
		return (1);
	return (0);
}

int		check_line(char *line, t_vars *v)
{
	if (*line == 'R')
	{
		v->e.res_w = cub_atoi(&line);
		v->e.res_h = cub_atoi(&line);
	}
	else if (*line == 'N' && *(line + 1) == 'O')
		v->e.so = cub_strdup(line, v);
	else if (*line == 'S' && *(line + 1) == 'O')
		v->e.no = cub_strdup(line, v);
	else if (*line == 'W' && *(line + 1) == 'E')
		v->e.we = cub_strdup(line, v);
	else if (*line == 'E' && *(line + 1) == 'A')
		v->e.ea = cub_strdup(line, v);
	else if (*line == 'S' && *(line + 1) == ' ')
		v->e.s_tex = cub_strdup(line, v);
	else if ((*line == 'F') && *(line + 1) == ' ')
		check_color(line, v, 'F');
	else if ((*line == 'C') && *(line + 1) == ' ')
		check_color(line, v, 'C');
	else if (ft_strchr(line, '1'))
		return (process_map(&line, v));
	return (0);
}

int		make_array(t_vars *v)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	v->e.array = malloc(sizeof(char *) * (v->e.rows + 1));
	while (v->e.map[i])
	{
		x = 0;
		v->e.array[y] = malloc(sizeof(char) * v->e.cols);
		while (v->e.map[i] && v->e.map[i] != '\n')
		{
			v->e.array[y][x] = v->e.map[i];
			if (v->e.array[y][x] == 'E' || v->e.array[y][x] == 'W' || v->e.array[y][x] == 'N' || v->e.array[y][x] == 'S')
			{
				v->e.or = v->e.array[y][x];
				v->posX = x + 0.5;
				v->posY = y + 0.5;
			}
			x++;
			i++;
		}
		v->e.array[y][x] = '\0';
		y++;
		i++;
		if (v->e.map[i] && v->e.map[i] != '1')
			return (ft_printf("invalid map"));
	}
	v->e.array[y] = NULL;
	return (0);
}

int		check_map(t_vars *v)
{
	int y;
	int x;

	y = 0;
	while (v->e.array[y])
	{
		if (v->e.array[y][0] != '1')
			return (ft_printf("invalid map"));
		if (v->e.array[y][v->e.cols] != '1')
			return (ft_printf("invalid map"));
		y++;
	}
	x = 0;
	while (v->e.array[0][x])
	{
		if (v->e.array[0][x] != '1')
			return (ft_printf("invalid map"));
		x++;
	}
	x = 0;
	while (v->e.array[v->e.rows - 1][x])
	{
		if (v->e.array[v->e.rows - 1][x] != '1')
			return (ft_printf("invalid map"));
		x++;
	}
	ft_printf("valid map");
	return (0);
}

int		get_elements(t_vars *v, int *fd)
{
	int ret;
	char *line;

	ret = 1;
	*fd = open("./map.cub", O_RDONLY);
	if (*fd < 0)
		return (0);
	while (ret)
	{
		ret = get_next_line(*fd, &line);
		v->e.error = check_line(line, v);
		free(line);
		if (v->e.error)
			return (0);
	}
	v->e.error = make_array(v);
	if (v->e.error)
		return (0);
	v->e.error = check_map(v);
	if (v->e.error)
		return (0);
	return (0);
}