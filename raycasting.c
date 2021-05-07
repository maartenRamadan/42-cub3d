/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 18:22:11 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/16 21:26:19 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_world(t_vars *v)
{
	if (v->w_dist < 0.1)
		v->w_dist = 0.1;
	v->ceiling = 0;
	v->height = v->res_h / v->w_dist;
	v->end = v->height / 2 + v->res_h / 2;
	v->start = -v->height / 2 + v->res_h / 2;
	v->dest_y = v->start;
	while (v->ceiling < v->start)
	{
		my_mlx_pixel_put_3d(v, v->x, v->ceiling, v->c_c);
		v->ceiling++;
	}
	while (v->dest_y < v->end)
	{
		my_mlx_pixel_put_tex(v);
		v->dest_y++;
		v->perc_y = (v->dest_y - v->start) / v->height;
	}
	while (v->end < v->res_h)
	{
		my_mlx_pixel_put_3d(v, v->x, v->end, v->f_color);
		v->end++;
	}
	if (v->spr)
		draw_sprites(v);
}

void	calc_perc_x(t_vars *v)
{
	if (v->side == 0)
		v->w_dist = v->delx * cos(fabs(v->angle - v->ray));
	else
		v->w_dist = v->dely * cos(fabs(v->angle - v->ray));
	if (v->side == 1)
	{
		v->t = 0;
		if (v->dirx < 0)
			v->perc_x = v->posx - fabs(v->dirx * v->dely);
		else
			v->perc_x = v->posx + fabs(v->dirx * v->dely);
		if (v->diry < 0)
			v->t = 1;
	}
	else
	{
		v->t = 2;
		if (v->diry < 0)
			v->perc_x = v->posy - fabs(v->diry * v->delx);
		else
			v->perc_x = v->posy + fabs(v->diry * v->delx);
		if (v->dirx < 0)
			v->t = 3;
	}
	v->perc_x -= (int)v->perc_x;
}

void	calc_dist(t_vars *v)
{
	while (1)
	{
		if (v->delx < v->dely)
		{
			v->side = 0;
			v->interx += v->stepx;
			if (v->array[v->intery][v->interx] == '2')
				collect_sprite_data(v);
			if (v->array[v->intery][v->interx] == '1')
				break ;
			v->delx += v->deltax;
		}
		else
		{
			v->side = 1;
			v->intery += v->stepy;
			if (v->array[v->intery][v->interx] == '2')
				collect_sprite_data(v);
			if (v->array[v->intery][v->interx] == '1')
				break ;
			v->dely += v->deltay;
		}
	}
	calc_perc_x(v);
}

void	find_intersect(t_vars *v)
{
	if (v->dirx < 0)
	{
		v->stepx = -1;
		v->distx = v->posx - (int)v->posx;
	}
	else
	{
		v->stepx = 1;
		v->distx = 1.0 - (v->posx - (int)v->posx);
	}
	if (v->diry < 0)
	{
		v->stepy = -1;
		v->disty = v->posy - (int)v->posy;
	}
	else
	{
		v->stepy = 1;
		v->disty = 1.0 - (v->posy - (int)v->posy);
	}
	v->interx = v->posx;
	v->intery = v->posy;
	v->dely = fabs(v->disty / v->diry);
	v->delx = fabs(v->distx / v->dirx);
	calc_dist(v);
}

void	cast_rays(t_vars *v)
{
	v->x = 0;
	v->plane = -1.0;
	while (v->plane < 1.0)
	{
		v->spr = 0;
		v->spr = 0;
		v->ray = v->angle - atan(v->plane / v->plane_dist);
		v->dirx = sin(v->ray);
		v->diry = cos(v->ray);
		if (v->ray > 2.0 * M_PI)
			v->ray -= (2.0 * M_PI);
		if (v->ray < 0)
			v->ray += 2.0 * M_PI;
		v->deltay = fabs(1.0 / v->diry);
		v->deltax = fabs(1.0 / v->dirx);
		find_intersect(v);
		create_world(v);
		v->plane += (2.0 / v->res_w);
		v->x++;
	}
}
