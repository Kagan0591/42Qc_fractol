/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:56:37 by tchalifo          #+#    #+#             */
/*   Updated: 2022/11/01 13:38:21 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* cx and cy are dynamic values for the Mandelbrot set
 * zx and zy are static values for the Mandelbrot set
 * Where x is reel num and y is imaginary num.
 */

#include "../inc/fractol.h"

static void	mandel_color_ajust(t_fractol *f)
{
	if ((f->f_opt.colors[1] + 1) >= 16777216)
		f->f_opt.color_switch = 1;
	else if ((f->f_opt.colors[1] - 1) < 0)
		f->f_opt.color_switch = 0;
	if (f->f_opt.color_switch == 0)
		f->f_opt.colors[1] += 1;
	else if (f->f_opt.color_switch == 1)
		f->f_opt.colors[1] -= 1;
}

static void	mandel_colorisation(t_fractol *f)
{
	if (f->mandelbrot.i == f->f_opt.max_iter + 1)
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
		create_trgb(0, 35, 35, 35));
	else if (f->mandelbrot.i == f->f_opt.max_iter)
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
		create_trgb(0, 255, 255, 255));
	else if ((f->mandelbrot.i % 2) == 0 && (f->mandelbrot.i == 2 || \
		f->mandelbrot.i == 3 || f->mandelbrot.i == 4))
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
		create_trgb(0, 35, 35, 35));
	else if ((f->mandelbrot.i % 2) == 0)
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
		(f->f_opt.colors[1]));
	else if ((f->mandelbrot.i % 4) == 0)
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
		(f->f_opt.colors[2]));
	else
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
		create_trgb(0, 35, 35, 35));
}

static void	mandel_calculus(t_fractol *f)
{
	long double	x_tmp;

	f->mandelbrot.i = 1;
	f->mandelbrot.zx = 0;
	f->mandelbrot.zy = 0;
	while (f->mandelbrot.i <= f->f_opt.max_iter)
	{
		x_tmp = f->mandelbrot.zx;
		f->mandelbrot.zx = (f->mandelbrot.zx * f->mandelbrot.zx) - \
			(f->mandelbrot.zy * f->mandelbrot.zy) + f->mandelbrot.cx;
		f->mandelbrot.zy = (2 * x_tmp * f->mandelbrot.zy) + f->mandelbrot.cy;
		if ((f->mandelbrot.zx * f->mandelbrot.zx) + (f->mandelbrot.zy * \
			f->mandelbrot.zy) > 4)
			break ;
		f->mandelbrot.i++;
	}
}

void	mandelbrot(t_fractol *f)
{
	f->mandelbrot.y_pos = 0;
	while (f->mandelbrot.y_pos <= (WIN_HEIGHT))
	{
		f->mandelbrot.cy = f->mandelbrot.y_axis_offset \
			- (f->mandelbrot.y_pos / f->mandelbrot.size);
		f->mandelbrot.x_pos = 0;
		while (f->mandelbrot.x_pos <= (WIN_WIDTH))
		{
			f->mandelbrot.cx = f->mandelbrot.x_axis_offset \
				+ (f->mandelbrot.x_pos / f->mandelbrot.size);
			f->mandelbrot.x_pos++;
			mandel_calculus(f);
			mandel_colorisation(f);
			mandel_color_ajust(f);
		}
		f->mandelbrot.y_pos++;
		mandel_color_ajust(f);
	}
}
