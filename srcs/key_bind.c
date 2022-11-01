/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:08:59 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/24 16:19:29 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* key value details
 * 123 = LEFT, 124 = Right, 125 = Down, 126 = Up, 49 = reCenter,
 * 69 = +(numpad), 78 = -(numpad)
 */

#include "../inc/fractol.h"

static void	list_of_keys(void)
{
	ft_putstr("You have used a not set key. Try these :\n");
	ft_putstr("displacement : \
		top arrow, bottom arrow, left arrow, right arrow\n");
}

static void	option_keys(int key, t_fractol *f)
{
	if (key == 24)
		f->f_opt.max_iter += 1;
	else if (key == 27)
		f->f_opt.max_iter -= 1;
}

static void	move_keys(int key, t_fractol *f)
{
	if (f->f_opt.type == 1 && key == 123)
		f->mandelbrot.x_axis_offset += 0.2;
	else if (f->f_opt.type == 2 && key == 123)
		f->julia.x_axis_offset += 0.2;
	else if (f->f_opt.type == 1 && key == 124)
		f->mandelbrot.x_axis_offset -= 0.2;
	else if (f->f_opt.type == 2 && key == 124)
		f->julia.x_axis_offset -= 0.2;
	else if (f->f_opt.type == 1 && key == 125)
		f->mandelbrot.y_axis_offset += 0.2;
	else if (f->f_opt.type == 2 && key == 125)
		f->julia.y_axis_offset += 0.2;
	else if (f->f_opt.type == 1 && key == 126)
		f->mandelbrot.y_axis_offset -= 0.2;
	else if (f->f_opt.type == 2 && key == 126)
		f->julia.y_axis_offset -= 0.2;
}

int	key_binding_mac(int key, t_fractol *f)
{
	if (key == 53)
		fractol_exit(0, f);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		move_keys(key, f);
	else if (key == 24 || key == 27)
	{
		option_keys(key, f);
	}
	else
	{
		list_of_keys();
	}
	fractal_updater(f);
	return (0);
}
