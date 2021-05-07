/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 12:08:11 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/17 09:59:27 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>

void	zero_struct(t_vars *v)
{
	v->no = NULL;
	v->so = NULL;
	v->we = NULL;
	v->ea = NULL;
	v->s_tex = NULL;
	v->map = NULL;
	v->error = 0;
	v->angle = M_PI;
	v->scope = M_PI / 3;
	v->plane_dist = 1.0 / tan(v->scope / 2.0);
	v->move = 0;
	v->crab = 0;
	v->rotate = 0;
	v->perc_y = 0;
	v->img_nb = 0;
	v->save = 0;
	v->cols = 0;
	v->rows = 0;
	v->ceiling = 0;
	v->c_c = 0;
	v->f_color = 0;
	v->or = '\0';
	v->res_h = 0;
	v->res_w = 0;
}

int		window_management(t_vars *v)
{
	v->mlx_3d = mlx_init();
	v->win = mlx_new_window(v->mlx_3d, v->res_w, v->res_h, "3d");
	v->i[0] = mlx_new_image(v->mlx_3d, v->res_w, v->res_h);
	v->add[0] = GET_ADD(v->i[0], &v->bpp3d, &v->ll3d, &v->e3d);
	v->i[1] = mlx_new_image(v->mlx_3d, v->res_w, v->res_h);
	v->add[1] = GET_ADD(v->i[1], &v->bpp3d, &v->ll3d, &v->e3d);
	v->mlx_tex1 = mlx_init();
	v->it1 = PNG(v->mlx_tex1, v->no, &v->iw[0], &v->ih[0]);
	v->mlx_tex2 = mlx_init();
	v->it2 = PNG(v->mlx_tex2, v->so, &v->iw[1], &v->ih[1]);
	v->mlx_tex3 = mlx_init();
	v->it3 = PNG(v->mlx_tex3, v->ea, &v->iw[2], &v->ih[2]);
	v->mlx_tex4 = mlx_init();
	v->it4 = PNG(v->mlx_tex4, v->we, &v->iw[3], &v->ih[3]);
	v->mlx_tex5 = mlx_init();
	v->it5 = PNG(v->mlx_tex5, v->s_tex, &v->iw[4], &v->ih[4]);
	if (!v->it1 || !v->it2 || !v->it3 || !v->it4 || !v->it5)
		return (ft_printf("Error\nInvalid texture or sprite path\n"));
	v->addt[0] = GET_ADD(v->it1, &v->bppt[0], &v->llt[0], &v->et[0]);
	v->addt[1] = GET_ADD(v->it2, &v->bppt[1], &v->llt[1], &v->et[1]);
	v->addt[2] = GET_ADD(v->it3, &v->bppt[2], &v->llt[2], &v->et[2]);
	v->addt[3] = GET_ADD(v->it4, &v->bppt[3], &v->llt[3], &v->et[3]);
	v->addt[4] = GET_ADD(v->it5, &v->bppt[4], &v->llt[4], &v->et[4]);
	return (0);
}

int		check_args(t_vars *v, int argc, char **argv)
{
	char *name;
	char *flag;
	char *map;

	name = "./cub3D";
	flag = "--save";
	map = ".cub";
	if (argc < 2 || argc > 3)
		return (ft_printf("Error\nInvalid number of arguments\n"));
	if (ft_strncmp(name, argv[0], 8))
		return (ft_printf("Error\nDid you mean \"./cub3D\"?\n"));
	if (!ft_strstr(argv[1], map))
		return (ft_printf("Error\nInvalid file extention (.cub)\n"));
	if (argc == 3 && ft_strncmp(flag, argv[2], 7))
		return (ft_printf("Error\nDid you mean --save?\n"));
	else if (argc == 3)
		v->save = 1;
	return (0);
}

int		main(int argc, char **argv)
{
	t_vars		v;
	int			fd;

	zero_struct(&v);
	if (check_args(&v, argc, argv))
		return (0);
	v.error = get_elements(&v, &fd, argv);
	if (v.error)
		return (0);
	mlx_get_screen_size(v.mlx_3d, &v.scr_x, &v.scr_y);
	if (v.res_h > v.scr_y && !v.save)
		v.res_h = v.scr_y;
	if (v.res_w > v.scr_x && !v.save)
		v.res_w = v.scr_x;
	v.error = window_management(&v);
	if (v.error)
		return (0);
	if (!v.save)
		ft_printf("Valid map\nGame started");
	else
		ft_printf("Valid map\nGenerating bmp file");
	hooks(&v);
	close(fd);
	return (0);
}
