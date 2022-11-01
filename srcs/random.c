/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:24:16 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/24 13:41:14 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	char_randomizer(void)
{
	int		fd;
	char	buffer[1];

	fd = open ("/dev/urandom", O_RDONLY);
	read (fd, &buffer, 1);
	close (fd);
	return (buffer[0]);
}
