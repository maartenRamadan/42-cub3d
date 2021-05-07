/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/13 15:11:57 by mramadan      #+#    #+#                 */
/*   Updated: 2020/04/16 21:48:34 by Marty         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./srcs/Libft/libft.h"
# include "./srcs/minilibx/mlx.h"
# include "./srcs/definitions.h"

typedef struct		s_sprite
{
	float		x;
	float		dist;
	float		angle;
	int			ray;
	int			side;
	float		hitx;
	float		hity;
	float		cen_x;
	float		cen_y;
	float		all_x;
	float		all_y;
	float		steps_to_allign;
	float		diry;
	float		dirx;
	float		incr_spr;
	float		incr_ray;
	float		end_spry;
	float		end_sprx;
	float		ray_dirx;
	float		ray_diry;
}					t_sprite;

typedef struct		s_vars {
	void			*mlx_3d;
	void			*win;
	void			*i[2];
	char			*add[2];
	int				bpp3d;
	int				ll3d;
	int				e3d;
	void			*mlx_tex1;
	void			*mlx_tex2;
	void			*mlx_tex3;
	void			*mlx_tex4;
	void			*mlx_tex5;
	void			*it1;
	void			*it2;
	void			*it3;
	void			*it4;
	void			*it5;
	char			*addt[5];
	int				bppt[5];
	int				llt[5];
	int				et[5];
	int				ih[5];
	int				iw[5];
	char			or;
	int				res_w;
	int				res_h;
	int				scr_y;
	int				scr_x;
	char			*s_tex;
	char			*map;
	char			**array;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	unsigned int	f_color;
	unsigned int	c_c;
	int				error;
	int				cols;
	int				rows;
	float			movx;
	float			movy;
	float			posx;
	float			posy;
	float			dirx;
	float			diry;
	float			stepx;
	float			stepy;
	int				interx;
	int				intery;
	float			distx;
	float			disty;
	float			delx;
	float			dely;
	float			deltax;
	float			deltay;
	float			w_dist;
	float			angle;
	float			scope;
	int				x;
	int				side;
	float			plane_dist;
	int				src_x;
	int				src_y;
	int				dest_x;
	int				dest_y;
	float			ray;
	float			perc_x;
	float			perc_y;
	int				t;
	float			crab;
	float			move;
	float			rotate;
	float			height;
	float			start;
	float			end;
	float			ceiling;
	float			plane;
	int				spr;
	t_sprite		s[254];
	int				img_nb;
	int				save;
	char			*c_allowed;
}					t_vars;

int					ft_printf(const char *str, ...);
int					get_next_line(int fd, char **line);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
void				ft_putnbr_fd(int n, int fd);
int					get_elements(t_vars *v, int *fd, char **argv);
char				*cub_strjoin(char **s1, char **s2);
int					check_color(char *line, t_vars *v, char c);
int					cub_strdup(char *line, char **s);
void				draw_2d_map(t_vars *v);
void				draw_player(t_vars *v, int color);
void				my_mlx_pixel_put(t_vars *v, int x, int y, int color);
void				draw_grid(t_vars *v);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				save_bmp(t_vars *v, char *addr);
void				collect_sprite_data(t_vars *v);
void				draw_sprites(t_vars *v);
void				sprite_side_0_down_right(t_vars *v);
void				sprite_side_1_down_right(t_vars *v);
void				sprite_side_0_up_left(t_vars *v);
void				sprite_side_1_down_left(t_vars *v);
void				sprite_side_0_down_left(t_vars *v);
void				sprite_side_1_up_right(t_vars *v);
void				sprite_side_0_up_right(t_vars *v);
void				sprite_side_1_up_left(t_vars *v);
void				my_mlx_pixel_put_sprite(t_vars *v, int x, int y);
void				my_mlx_pixel_put_tex(t_vars *v);
void				my_mlx_pixel_put_3d(t_vars *v, int x, int y,
					unsigned int color);
void				cast_rays(t_vars *v);
void				hooks(t_vars *v);
void				flood_line(t_vars *v, int x, int y);
int					fill_array(t_vars *v, int *x, int y, int *i);
int					check_white_space_only(char *line);
int					move_player(t_vars *v);
int					cub_atoi(char **line, char el, int c, t_vars *v);

#endif
