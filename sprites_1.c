/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites_1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 18:02:42 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/15 17:34:14 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprites(t_vars *v)
{
	float	x;
	float	y;

	while (v->spr > 0)
	{
		v->s[v->spr].dist = fabs(sqrt(pow(v->posy - v->s[v->spr].cen_y, 2) +
		pow(v->posx - v->s[v->spr].cen_x, 2)) * cos(fabs(v->angle - v->ray)));
		v->t = 4;
		v->height = (float)v->res_h / v->s[v->spr].dist;
		v->end = v->height / 2 + v->res_h / 2;
		v->start = -v->height / 2 + v->res_h / 2;
		v->dest_y = v->start;
		x = v->s[v->spr].x * v->iw[v->t];
		while (v->dest_y < v->end)
		{
			v->perc_y = fabs(((float)v->dest_y - v->start) / v->height);
			y = v->perc_y * v->ih[v->t];
			my_mlx_pixel_put_sprite(v, x, y);
			v->dest_y++;
		}
		v->spr--;
	}
}

void	initialize_sprite_data(t_vars *v)
{
	v->spr++;
	if (v->side == 0)
	{
		v->s[v->spr].hity = v->delx * v->diry + v->posy;
		v->s[v->spr].hitx = v->delx * v->dirx + v->posx;
	}
	else
	{
		v->s[v->spr].hity = v->dely * v->diry + v->posy;
		v->s[v->spr].hitx = v->dely * v->dirx + v->posx;
	}
	v->s[v->spr].angle = v->ray - M_PI / 2;
	if (v->s[v->spr].angle < 0)
		v->s[v->spr].angle += M_PI * 2;
	v->s[v->spr].cen_x = v->interx + 0.5;
	v->s[v->spr].cen_y = v->intery + 0.5;
	v->s[v->spr].dirx = sin(v->s[v->spr].angle);
	v->s[v->spr].diry = cos(v->s[v->spr].angle);
	v->s[v->spr].incr_spr = fabs(v->s[v->spr].dirx / v->s[v->spr].diry * 0.001);
	v->s[v->spr].incr_ray = fabs(v->dirx / v->diry * 0.001);
}

void	collect_sprite_data(t_vars *v)
{
	initialize_sprite_data(v);
	if (v->side == 0)
	{
		if (v->diry > 0 && v->dirx < 0)
			sprite_side_0_down_right(v);
		if (v->diry > 0 && v->dirx > 0)
			sprite_side_0_down_left(v);
		if (v->diry < 0 && v->dirx > 0)
			sprite_side_0_up_right(v);
		if (v->diry < 0 && v->dirx < 0)
			sprite_side_0_up_left(v);
	}
	else
	{
		if (v->diry > 0 && v->dirx < 0)
			sprite_side_1_down_right(v);
		if (v->diry > 0 && v->dirx > 0)
			sprite_side_1_down_left(v);
		if (v->diry < 0 && v->dirx > 0)
			sprite_side_1_up_right(v);
		if (v->diry < 0 && v->dirx < 0)
			sprite_side_1_up_left(v);
	}
}
