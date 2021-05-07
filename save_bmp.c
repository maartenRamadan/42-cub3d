/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_bmp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 17:43:25 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/15 12:23:49 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_header(t_vars *v, int fd)
{
	unsigned int file_size;
	unsigned int offset;

	file_size = v->res_h * v->res_w * 4 + 54;
	offset = 54;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &offset, 4);
}

void	fill_info_header(t_vars *v, int fd)
{
	unsigned int	size;
	unsigned short	plane;
	unsigned short	bpp;

	size = 40;
	plane = 1;
	bpp = 32;
	write(fd, &size, 4);
	write(fd, &v->res_w, 4);
	write(fd, &v->res_h, 4);
	write(fd, &plane, 2);
	write(fd, &bpp, 2);
	plane = 0;
	while (plane < 24)
	{
		write(fd, "\0", 1);
		plane++;
	}
}

void	save_bmp(t_vars *v, char *addr)
{
	int fd;
	int y;
	int x;

	fd = open("screenshot.bmp", O_TRUNC | O_WRONLY | O_CREAT, 0777);
	fill_header(v, fd);
	fill_info_header(v, fd);
	y = v->res_h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < v->res_w)
		{
			write(fd, &addr[y * v->ll3d + x * 4], 4);
			x++;
		}
		y--;
	}
}
