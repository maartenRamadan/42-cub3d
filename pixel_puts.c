/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_puts.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 18:17:05 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/15 12:17:02 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put_3d(t_vars *v, int x, int y, unsigned int color)
{
	char	*dst;

	if (v->x >= 0 && v->x < v->res_w && v->dest_y < v->res_h && v->dest_y >= 0)
	{
		dst = v->add[v->img_nb] + (y * v->ll3d + x * (v->bpp3d / 8));
		*(unsigned int*)dst = color;
	}
}

void	my_mlx_pixel_put_tex(t_vars *v)
{
	int		x;
	int		y;
	char	*dst;
	char	*src;

	x = v->perc_x * v->iw[v->t];
	y = v->perc_y * v->ih[v->t];
	if (v->x >= 0 && v->x < v->res_w && v->dest_y < v->res_h && v->dest_y >= 0)
	{
		dst = v->add[v->img_nb] + (v->dest_y * v->ll3d + v->x * (v->bpp3d / 8));
		src = v->addt[v->t] + y * v->llt[v->t] + x * (v->bppt[v->t] / 8);
		*(unsigned int*)dst = *(unsigned int*)src;
	}
}

void	my_mlx_pixel_put_sprite(t_vars *v, int x, int y)
{
	char	*dst;
	char	*src;

	if (v->x >= 0 && v->x < v->res_w && v->dest_y < v->res_h && v->dest_y >= 0)
	{
		dst = v->add[v->img_nb] + (v->dest_y * v->ll3d + v->x * (v->bpp3d / 8));
		src = v->addt[v->t] + y * v->llt[v->t] + x * (v->bppt[v->t] / 8);
		if (*(unsigned int*)src != 0x00000000)
			*(unsigned int*)dst = *(unsigned int*)src;
	}
}
