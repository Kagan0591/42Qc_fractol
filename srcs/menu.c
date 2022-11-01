/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:05:18 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/20 09:44:30 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	str_toscreen(t_fractol *f, int x, int y, char *string)
{
	mlx_string_put(f->mlx.mlx, f->mlx.win, x, y, \
create_trgb(0, 255, 255, 255), string);
}

void	num_toscreen(t_fractol *f, int x, int y, int values)
{
	mlx_string_put(f->mlx.mlx, f->mlx.win, x, y, \
create_trgb(0, 255, 255, 255), ft_itoa(values));
}
