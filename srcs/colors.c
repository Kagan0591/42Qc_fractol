/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:38:21 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/24 16:19:29 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	create_rand_rgb(void)
{
	char	red;
	char	green;
	char	blue;
	char	transparency;

	transparency = 0;
	red = char_randomizer();
	green = char_randomizer();
	blue = char_randomizer();
	return (*(int *)(unsigned char [4]){blue, green, red, transparency});
}

int	*create_color_set(int gen_amount)
{
	int	*colors;
	int	i;

	i = 0;
	colors = malloc(sizeof(int) * gen_amount);
	while (i < gen_amount)
	{
		colors[i] = create_rand_rgb();
		i++;
	}
	return (colors);
}
