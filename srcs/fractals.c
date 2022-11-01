/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 08:15:40 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/20 09:39:34 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mandelbrot_init(t_formula_values *data)
{
	data->size = 300;
	data->x_axis_offset = -2.7;
	data->y_axis_offset = 1.2;
}

void	julia_init(t_formula_values *data)
{
	data->size = 300;
	data->x_axis_offset = -2.1;
	data->y_axis_offset = 1.2;
	data->cy = 0.823;
	data->cx = -0.2;
}

void	fractal_updater(t_fractol *f)
{
	if (f->f_opt.type == 1)
		mandelbrot(f);
	else if (f->f_opt.type == 2)
		julia(f);
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img_addr, 0, 0);
}
