/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Marty <Marty@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/16 09:42:04 by Marty         #+#    #+#                 */
/*   Updated: 2020/04/16 22:31:23 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		release(int keycode, t_vars *v)
{
	if (keycode == 1 || keycode == 13)
		v->move = 0;
	else if (keycode == 0 || keycode == 2)
		v->crab = 0;
	else if (keycode == 123 || keycode == 124)
		v->rotate = 0;
	return (keycode);
}

int		destroy_window(t_vars *v)
{
	int i;

	i = 0;
	while (v->array[i])
	{
		free(v->array[i]);
		i++;
	}
	free(v->array);
	free(v->so);
	free(v->no);
	free(v->we);
	free(v->ea);
	free(v->s_tex);
	mlx_destroy_window(v->mlx_3d, v->win);
	ft_printf("\nGame closed, thanks for playing!\n");
	exit(0);
	return (0);
}

int		press(int keycode, t_vars *v)
{
	if (keycode == 53)
		destroy_window(v);
	if (keycode == 1)
		v->move = 0.03;
	if (keycode == 13)
		v->move = -0.05;
	if (keycode == 2)
		v->crab = 0.03;
	if (keycode == 0)
		v->crab = -0.03;
	if (keycode == 123)
		v->rotate = 0.03;
	if (keycode == 124)
		v->rotate = -0.03;
	return (keycode);
}

void	hooks(t_vars *v)
{
	if (v->or == 'S')
		v->angle = 0;
	if (v->or == 'E')
		v->angle = M_PI / 2;
	if (v->or == 'W')
		v->angle = M_PI * 1.5;
	mlx_hook(v->win, 2, 1L << 0, press, v);
	mlx_hook(v->win, 3, 1L << 0, release, v);
	mlx_hook(v->win, 17, 1L << 17, destroy_window, v);
	mlx_loop_hook(v->mlx_3d, move_player, v);
	if (v->save)
	{
		move_player(v);
		return ;
	}
	mlx_loop(v->mlx_3d);
}
