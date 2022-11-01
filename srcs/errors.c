/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:04:39 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/31 17:00:46 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	bad_arguments_exit(t_fractol *f, int error_code)
{
	ft_putstr_fd(strerror(error_code), 2);
	ft_putstr(" -- You can choose between two different fractals : \
\n- Mandelbrot\n- Julia\n\nAlso, the Julia set can take a decimal number from \
-2 to 2 to create a different set or use the word auto \
for mouse tracking modifier.\n\n");
	free(f);
	exit(error_code);
}

void	julia_bad_arguments(void)
{
	ft_putstr_fd("The additional arguments concerning Julia (if there is) \
are not valid. they are going to be ignore and the programme are going \
to use the base values\n", 2);
}
