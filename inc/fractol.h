/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:24:52 by tchalifo          #+#    #+#             */
/*   Updated: 2022/11/01 13:36:22 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define FRACTAL_MAX_ITER 30
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../.mlx/mlx.h"

/*
 * Struct containing all mlx related vars
 */
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img_addr;
	char	*pixel_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		mouse_pos_x;
	int		mouse_pos_y;
}	t_mlx;

/*
 * Struct for fractal related values
 */
typedef struct s_formula_values
{
	int			x_pos;
	int			y_pos;
	int			i;
	long double	cx;
	long double	cy;
	long double	zx;
	long double	zy;
	long double	size;
	long double	x_axis_offset;
	long double	y_axis_offset;
}t_formula_values;

/*
 * Struct for fractal options
 */
typedef struct s_fractal_options
{
	int	max_iter;
	int	type;
	int	julia_morph;
	int	*colors;
	int	color_switch;
}	t_fractal_options;

/*
 * Main struct containing others struct
 */
typedef struct s_fractol
{
	t_mlx				mlx;
	t_fractal_options	f_opt;
	t_formula_values	mandelbrot;
	t_formula_values	julia;
	char				**argv_cpy;
}	t_fractol;

/*
 * Core functions
 */
void			init_mlx(t_fractol *f);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
char			char_randomizer(void);
int				*create_color_set(int gen_amount);
void			image_refresh(t_mlx *mlx_data);
void			hooks_manager(t_fractol *f);
int				key_binding_mac(int key, t_fractol *f);
int				mouse_binding_mac(int key, int x, int y, t_fractol *f);
int				mouse_get_pos_mac(int x, int y, t_fractol *f);
void			mouse_pos_update(t_mlx *mlx_data);
void			bad_arguments_exit(t_fractol *f, int error_code);
void			julia_bad_arguments(void);
void			fractol_exit(int error_code, t_fractol *f);
void			str_toscreen(t_fractol *f, int x, int y, char *string);
void			num_toscreen(t_fractol *f, int x, int y, int values);

/*
 * Fractal functions
 */
void			mandelbrot_init(t_formula_values *data);
void			mandelbrot(t_fractol *f);
void			julia_init(t_formula_values *data);
void			julia(t_fractol *f);
void			fractal_updater(t_fractol *f);

#endif