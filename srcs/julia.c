/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:16:53 by tchalifo          #+#    #+#             */
/*   Updated: 2022/11/01 13:37:00 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* cx and cy are static values for the Julia set
 * zx and zy are dynamic values for the Julia set
 * Where x is reel num and y is imaginary num.
 */

#include "../inc/fractol.h"

static void	julia_colorisation(t_fractol *f)
{
	if (f->julia.i == (f->f_opt.max_iter + 1))
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			create_trgb(0, 151, 117, 170));
	else if (f->julia.i == (f->f_opt.max_iter - 2))
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			f->f_opt.colors[1]);
	else if (f->julia.i == (f->f_opt.max_iter - 4))
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			f->f_opt.colors[2]);
	else if (f->julia.i == (f->f_opt.max_iter - 6))
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			f->f_opt.colors[3]);
	else if (f->julia.i == (f->f_opt.max_iter - 8))
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			f->f_opt.colors[4]);
	else if (f->julia.i == (f->f_opt.max_iter - 10))
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			f->f_opt.colors[5]);
	else
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			create_trgb(0, 35, 35, 35));
}

static void	julia_calculus(t_fractol *f)
{
	long double	x_tmp;

	f->julia.i = 1;
	f->julia.zx = f->julia.x_axis_offset + (f->julia.x_pos / f->julia.size);
	f->julia.zy = f->julia.y_axis_offset - (f->julia.y_pos / f->julia.size);
	while (f->julia.i <= f->f_opt.max_iter)
	{
		x_tmp = f->julia.zx;
		f->julia.zx = (f->julia.zx * f->julia.zx) - (f->julia.zy * f->julia.zy) \
			+ f->julia.cx;
		f->julia.zy = (2 * x_tmp * f->julia.zy) + f->julia.cy;
		if ((f->julia.zx * f->julia.zx) + (f->julia.zy * f->julia.zy) > 4)
			break ;
		f->julia.i++;
	}
}

void	julia(t_fractol *f)
{
	f->julia.y_pos = 0;
	while (f->julia.y_pos <= (WIN_HEIGHT))
	{
		if (f->f_opt.julia_morph == 1)
		{
			f->julia.cy = f->mlx.mouse_pos_y / 2500;
			printf("%d - ", f->mlx.mouse_pos_y);
		}
		else if (f->f_opt.julia_morph == 2)
			f->julia.cy = ft_atold(f->argv_cpy[3]);
		f->julia.x_pos = 0;
		while (f->julia.x_pos <= (WIN_WIDTH))
		{
			if (f->f_opt.julia_morph == 1)
				f->julia.cx = f->mlx.mouse_pos_x / 1400;
			else if (f->f_opt.julia_morph == 2)
				f->julia.cx = ft_atold(f->argv_cpy[2]);
			f->julia.x_pos++;
			julia_calculus(f);
			julia_colorisation(f);
		}
		f->julia.y_pos++;
	}
}
