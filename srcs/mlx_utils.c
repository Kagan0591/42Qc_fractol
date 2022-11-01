/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:17:40 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/31 14:01:07 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_mlx(t_fractol *f)
{
	f->mlx.mlx = mlx_init();
	if (!f->mlx.mlx)
		fractol_exit(1, f);
	f->mlx.win = \
		mlx_new_window(f->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Thomas Fractol");
	f->mlx.img_addr = \
		mlx_new_image(f->mlx.mlx, (WIN_WIDTH + 1), (WIN_HEIGHT + 1));
	f->mlx.pixel_addr = \
		mlx_get_data_addr(f->mlx.img_addr, &f->mlx.bits_per_pixel, \
		&f->mlx.line_length, &f->mlx.endian);
	f->mlx.mouse_pos_x = 0;
	f->mlx.mouse_pos_y = 0;
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->pixel_addr + (y * mlx->line_length) + \
		(x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	image_refresh(t_mlx *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_addr);
	mlx_data->img_addr = \
		mlx_new_image(mlx_data->mlx, (WIN_WIDTH + 1), (WIN_HEIGHT + 1));
	mlx_data->pixel_addr = \
		mlx_get_data_addr(mlx_data->img_addr, &mlx_data->bits_per_pixel, \
			&mlx_data->line_length, &mlx_data->endian);
}
