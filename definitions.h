/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   definitions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/13 13:39:47 by mramadan       #+#    #+#                */
/*   Updated: 2020/03/13 17:21:18 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include "cub3d.h"

# define WIN_3D v->img.win_3d
# define MLX_3D v->img.mlx_3d
# define IMG_3D v->img.img_3d
# define ADR_3D v->img.addr_3d
# define MLX_TEX v->img.mlx_tex
# define IMG_TEX v->img.img_tex
# define ADD_3D v->img.addr_3d[v->img_nb]
# define ADD_TEX v->img.addr_tex[v->tex]
# define ADD_TX v->img.addr_tex
# define LL_TEX v->img.line_length_tex[v->tex]
# define LL_TX v->img.line_length_tex
# define LL_3D v->img.line_length_3d
# define BPP_TEX v->img.bits_per_pixel_tex[v->tex]
# define BPP_TX v->img.bits_per_pixel_tex
# define BPP_3D v->img.bits_per_pixel_3d
# define NDIAN_TEX v->img.endian_tex
# define NDIAN_3D v->img.endian_3d
# define SPRITE v->s[v->spr]
# define X_INSIDE_WIN v->x >= 0 && v->x < v->e.res_w
# define Y_INSIDE_WIN v->dest_y < v->e.res_h && v->dest_y >= 0
# define TEX_WIDTH v->img.img_width[v->tex]
# define TEX_HEIGHT v->img.img_height[v->tex]
# define TX_WIDTH v->img.img_width
# define TX_HEIGHT v->img.img_height
# define PNG mlx_png_file_to_image
# define GET_ADD mlx_get_data_addr
# define UP_DOWN v->e.array[y - 1][x] == ' ' || v->e.array[y + 1][x] == ' '
# define LEFT_RIGHT v->e.array[y][x - 1] == ' ' || v->e.array[y][x + 1] == ' '
# define NEW_POSY (int)(v->posy - v->move * v->diry)
# define NEW_POSX (int)(v->posy - v->move * v->diry)

#endif
