/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 18:26:30 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/16 09:46:07 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		move(t_vars *v)
{
	v->dirx = sin(v->angle);
	v->diry = cos(v->angle);
	v->movx = v->posx - v->move * v->dirx;
	if (v->array[(int)v->posy][(int)v->movx] != '1')
		v->posx = v->movx;
	v->movy = v->posy - v->move * v->diry;
	if (v->array[(int)v->movy][(int)v->posx] != '1')
		v->posy = v->movy;
	cast_rays(v);
	if (v->save)
		save_bmp(v, v->add[0]);
	else
		mlx_put_image_to_window(v->mlx_3d, v->win, v->i[v->img_nb], 0, 0);
	v->img_nb = (v->img_nb + 1) % 2;
	return (0);
}

int		crab(t_vars *v)
{
	v->dirx = sin(v->angle + M_PI_2);
	v->diry = cos(v->angle + M_PI_2);
	v->movx = v->posx - v->crab * v->dirx;
	if (v->array[(int)v->posy][(int)v->movx] != '1')
		v->posx = v->movx;
	v->movy = v->posy - v->crab * v->diry;
	if (v->array[(int)v->movy][(int)v->posx] != '1')
		v->posy = v->movy;
	return (0);
}

int		move_player(t_vars *v)
{
	v->angle += v->rotate;
	crab(v);
	move(v);
	cast_rays(v);
	if (v->save)
		save_bmp(v, v->add[0]);
	else
		mlx_put_image_to_window(v->mlx_3d, v->win, v->i[v->img_nb], 0, 0);
	v->img_nb = (v->img_nb + 1) % 2;
	return (0);
}
