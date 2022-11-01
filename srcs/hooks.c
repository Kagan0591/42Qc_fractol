/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:04:05 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/18 15:10:58 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	close_win(t_fractol *f)
{
	fractol_exit(0, f);
	return (0);
}

void	hooks_manager(t_fractol *f)
{
	mlx_hook(f->mlx.win, 17, 0, close_win, &f->mlx);
	mlx_hook(f->mlx.win, 2, 0, key_binding_mac, &f->mlx);
	mlx_mouse_hook(f->mlx.win, mouse_binding_mac, &f->mlx);
	mlx_hook(f->mlx.win, 6, 0, mouse_get_pos_mac, f->mlx.mlx);
}
