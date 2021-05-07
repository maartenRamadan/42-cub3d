/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check_1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 12:56:41 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/16 22:24:48 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		process_map(char **line, t_vars *v)
{
	int		len;
	char	*tmp;

	if (!v->map)
		v->map = calloc(1, 1);
	tmp = v->map;
	v->rows++;
	len = ft_strlen(*line);
	if (len > v->cols)
		v->cols = len;
	v->map = cub_strjoin(&v->map, line);
	free(tmp);
	if (v->error)
		return (ft_printf("Error\nMalloc fail\n"));
	return (0);
}

int		check_line(char *line, t_vars *v)
{
	if (*line == 'R' && !v->rows)
	{
		line++;
		v->res_w = cub_atoi(&line, 'R', 1, v);
		v->res_h = cub_atoi(&line, 'R', 2, v);
	}
	else if (*line == 'N' && *(line + 1) == 'O' && !v->rows)
		v->error = cub_strdup(line, &v->so);
	else if (*line == 'S' && *(line + 1) == 'O' && !v->rows)
		v->error = cub_strdup(line, &v->no);
	else if (*line == 'W' && *(line + 1) == 'E' && !v->rows)
		v->error = cub_strdup(line, &v->we);
	else if (*line == 'E' && *(line + 1) == 'A' && !v->rows)
		v->error = cub_strdup(line, &v->ea);
	else if (*line == 'S' && *(line + 1) == ' ' && !v->rows)
		v->error = cub_strdup(line, &v->s_tex);
	else if (*line == 'F' && !v->rows)
		v->error = check_color(line, v, 'F');
	else if (*line == 'C' && !v->rows)
		v->error = check_color(line, v, 'C');
	else if (ft_strchr(line, '1'))
		return (process_map(&line, v));
	else if (*line && check_white_space_only(line))
		return (ft_printf("Error\nInvalid map!\n"));
	return (v->error);
}

int		make_array(t_vars *v, int i)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	v->rows += 2;
	v->array = malloc(sizeof(char *) * (v->rows + 1));
	if (!v->array)
		return (ft_printf("Error\nMalloc fail\n"));
	v->array[y] = malloc(sizeof(char) * (v->cols + 1));
	flood_line(v, x, y);
	while (y < v->rows - 1)
	{
		if (!v->array[y])
			return (ft_printf("Error\nMalloc fail\n"));
		y++;
		x = 0;
		v->array[y] = malloc(sizeof(char) * v->cols + 1);
		if (fill_array(v, &x, y, &i))
			return (1);
		flood_line(v, x, y);
		i++;
	}
	v->array[y + 1] = NULL;
	return (0);
}

int		check_map(t_vars *v)
{
	int		y;
	int		x;
	char	*allowed;

	allowed = "012NE 	SW\n";
	y = 1;
	while (y < v->rows)
	{
		x = 0;
		while (x < v->cols)
		{
			if (v->array[y][x] == '0' || v->array[y][x] == v->or
			|| v->array[y][x] == '2')
			{
				if (v->array[y - 1][x] == ' ' || v->array[y + 1][x] == ' ' ||
				v->array[y][x - 1] == ' ' || v->array[y][x + 1] == ' ')
					return (ft_printf("Error\nMap not closed\n"));
				if (!ft_strchr(allowed, v->array[y][x]))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		get_elements(t_vars *v, int *fd, char **argv)
{
	int		ret;
	char	*line;

	ret = 1;
	*fd = open(argv[1], O_RDONLY);
	if (*fd < 0)
		return (ft_printf("Error\nCouldn't open file\n"));
	while (ret)
	{
		ret = get_next_line(*fd, &line);
		v->error = check_line(line, v);
		free(line);
		if (v->error)
			return (1);
	}
	if (v->res_w < 0 || v->res_h < 0)
		return (ft_printf("Error\nInvalid or double resolution\n"));
	v->error = make_array(v, 0);
	free(v->map);
	if (!v->so || !v->no || !v->we || !v->ea || !v->s_tex || !v->c_c ||
	!v->f_color || !v->res_h || !v->res_w || !v->map || !v->or)
		return (ft_printf("Error\nSomething's missing...\n"));
	if (v->error)
		return (1);
	return (check_map(v));
}
