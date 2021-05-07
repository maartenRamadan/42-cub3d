/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check_4.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Marty <Marty@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/23 17:08:46 by Marty         #+#    #+#                 */
/*   Updated: 2020/04/23 17:25:02 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		prep_array(t_vars *v)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	v->rows += 2;
	v->array = malloc(sizeof(char *) * (v->rows + 1));
	if (!v->array)
		return (ft_printf("Error\nMalloc fail\n"));
	v->array[y] = malloc(sizeof(char) * (v->cols + 1));
	if (!v->array[y])
		return (ft_printf("Error\nMalloc fail\n"));
	flood_line(v, x, y);
	return (0);
}
