/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:24:20 by tchalifo          #+#    #+#             */
/*   Updated: 2022/11/01 13:24:44 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return value : 0 = All good, 1 = Memory alloc probleme, 22 = Bad arguments
 *
 */
#include "../inc/fractol.h"

void	fractol_exit(int error_code, t_fractol *f)
{
	int	i;

	i = 0;
	mlx_destroy_image(f->mlx.mlx, f->mlx.img_addr);
	mlx_destroy_window(f->mlx.mlx, f->mlx.win);
	if (f->f_opt.type == 2)
	{
		while (f->argv_cpy[i] != NULL)
		{
			free(f->argv_cpy[i]);
			i++;
		}
		free(f->argv_cpy);
	}
	free(f->f_opt.colors);
	free(f);
	exit(error_code);
}

static void	args_validation(int argc, char **argv, t_fractol *f)
{
	if (argc >= 2)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") == 0 \
			|| ft_strcmp(argv[1], "mandelbrot") == 0)
			f->f_opt.type = 1;
		else if (ft_strcmp(argv[1], "Julia") == 0 \
			|| ft_strcmp(argv[1], "julia") == 0)
		{
			if (argc == 4 && (ft_strisdecimal(argv[2]) == 0 \
				&& ft_strisdecimal(argv[3]) == 0))
				f->f_opt.julia_morph = 2;
			else
				julia_bad_arguments();
			f->f_opt.type = 2;
		}
		else
			bad_arguments_exit(f, 22);
	}
	else
		bad_arguments_exit(f, 22);
}

static void	set_initial_vars(int argc, char **argv, t_fractol *f)
{
	f->f_opt.max_iter = FRACTAL_MAX_ITER;
	f->f_opt.color_switch = 0;
	f->f_opt.colors = create_color_set(10);
	if (f->f_opt.type == 1)
		mandelbrot_init(&f->mandelbrot);
	else if (f->f_opt.type == 2)
	{
		julia_init(&f->julia);
		f->argv_cpy = ft_argvcpy(argc, argv);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	*f;

	f = (t_fractol *)malloc(sizeof(t_fractol));
	if (!f)
		return (1);
	args_validation(argc, argv, f);
	set_initial_vars(argc, argv, f);
	init_mlx(f);
	if (f->f_opt.type == 1)
	{
		ft_putstr("\nThis is Mandelbrot !!\n\n");
		mandelbrot(f);
	}
	else if (f->f_opt.type == 2)
	{
		ft_putstr("\nThis is Julia !!\n\n");
		julia(f);
	}
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img_addr, 0, 0);
	hooks_manager(f);
	mlx_loop(f->mlx.mlx);
	fractol_exit(0, f);
	return (0);
}
