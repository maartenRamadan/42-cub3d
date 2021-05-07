/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites_2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 18:09:52 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/15 12:13:54 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_side_0_down_right(t_vars *v)
{
	float i;

	v->s[v->spr].all_y = v->s[v->spr].cen_y + 0.5 / tan(v->s[v->spr].angle);
	i = (v->s[v->spr].all_y - v->s[v->spr].hity) / (v->s[v->spr].incr_spr +
	v->s[v->spr].incr_ray);
	v->s[v->spr].hitx -= i * 0.001;
	v->s[v->spr].hity += i * v->s[v->spr].incr_spr;
	v->s[v->spr].end_spry = v->s[v->spr].cen_y + fabs(v->s[v->spr].diry / 2);
	v->s[v->spr].x = fabs((v->s[v->spr].hity - v->s[v->spr].end_spry) /
	v->s[v->spr].diry);
}

void	sprite_side_1_down_right(t_vars *v)
{
	float i;

	v->s[v->spr].all_x = v->s[v->spr].cen_x - 0.5 * tan(v->s[v->spr].angle);
	i = (-v->s[v->spr].all_x + v->s[v->spr].hitx) / (v->s[v->spr].incr_ray +
	v->s[v->spr].incr_spr);
	v->s[v->spr].hity += i * 0.001;
	v->s[v->spr].hitx -= i * v->s[v->spr].incr_ray;
	v->s[v->spr].end_sprx = v->s[v->spr].cen_x - fabs(v->s[v->spr].dirx / 2);
	v->s[v->spr].x = 1 - fabs((v->s[v->spr].hitx - v->s[v->spr].end_sprx) /
	v->s[v->spr].dirx);
}

void	sprite_side_0_up_left(t_vars *v)
{
	float i;

	v->s[v->spr].all_y = v->s[v->spr].cen_y + 0.5 / tan(v->s[v->spr].angle);
	i = (-v->s[v->spr].all_y + v->s[v->spr].hity) / (v->s[v->spr].incr_spr +
	v->s[v->spr].incr_ray);
	v->s[v->spr].hitx -= i * 0.001;
	v->s[v->spr].hity -= i * v->s[v->spr].incr_spr;
	v->s[v->spr].end_spry = v->s[v->spr].cen_y - fabs(v->s[v->spr].diry / 2);
	v->s[v->spr].x = 1 - fabs((v->s[v->spr].hity - v->s[v->spr].end_spry) /
	v->s[v->spr].diry);
}

void	sprite_side_1_down_left(t_vars *v)
{
	float i;

	v->s[v->spr].all_x = v->s[v->spr].cen_x - 0.5 * tan(v->s[v->spr].angle);
	i = (v->s[v->spr].all_x - v->s[v->spr].hitx) / (v->s[v->spr].incr_ray +
	v->s[v->spr].incr_spr);
	v->s[v->spr].hity += i * 0.001;
	v->s[v->spr].hitx += i * v->s[v->spr].incr_ray;
	v->s[v->spr].end_sprx = v->s[v->spr].cen_x + fabs(v->s[v->spr].dirx / 2);
	v->s[v->spr].x = fabs((v->s[v->spr].hitx - v->s[v->spr].end_sprx) /
	v->s[v->spr].dirx);
}

void	sprite_side_0_down_left(t_vars *v)
{
	float i;

	v->s[v->spr].all_y = v->s[v->spr].cen_y - 0.5 / tan(v->s[v->spr].angle);
	i = (v->s[v->spr].all_y - v->s[v->spr].hity) / (v->s[v->spr].incr_spr +
	v->s[v->spr].incr_ray);
	v->s[v->spr].hitx += i * 0.001;
	v->s[v->spr].hity += i * v->s[v->spr].incr_spr;
	v->s[v->spr].end_spry = v->s[v->spr].cen_y + fabs(v->s[v->spr].diry / 2);
	v->s[v->spr].x = 1 - fabs((v->s[v->spr].hity - v->s[v->spr].end_spry) /
	v->s[v->spr].diry);
}
