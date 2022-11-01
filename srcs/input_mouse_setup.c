/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse_setup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:35:18 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/20 09:12:03 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mouse_binding_mac(int key, int x, int y, t_fractol *f)
{
	(void) x;
	(void) y;
	if (f->f_opt.type == 1 && key == 4)
		f->mandelbrot.size = f->mandelbrot.size * 1.2;
	if (f->f_opt.type == 2 && key == 4)
		f->julia.size = f->julia.size * 1.2;
	else if (f->f_opt.type == 1 && key == 5)
		f->mandelbrot.size = f->mandelbrot.size * 0.8;
	else if (f->f_opt.type == 2 && key == 5)
		f->julia.size = f->julia.size * 0.8;
	fractal_updater(f);
	return (0);
}

int	mouse_get_pos_mac(int x, int y, t_fractol *f)
{
	f->mlx.mouse_pos_x = x;
	f->mlx.mouse_pos_y = y;
	if (f->f_opt.julia_morph == 1)
		fractal_updater(f);
	return (0);
}
