/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:01:30 by llupache          #+#    #+#             */
/*   Updated: 2025/05/22 20:13:21 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	generate_fract(t_fractal *fract)
{
	t_image	*image;

	if (fract->im_fr)
	{
		mlx_destroy_image(fract->mlx, fract->im_fr->img);
		free(fract->im_fr);
	}
	image = malloc(sizeof(t_image));
	fract->im_fr = image;
	fract->im_fr->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	fract->im_fr->addr = mlx_get_data_addr(fract->im_fr->img,
			&fract->im_fr->bits_per_pixel, &fract->im_fr->size_line,
			&fract->im_fr->endian);
	fract->y = 0;
	generate_fract_2(fract);
	mlx_put_image_to_window(fract->mlx, fract->window, fract->im_fr->img, 0, 0);
	put_strings(fract);
}

int	zoom(int button, int x, int y, t_fractal *fract)
{
	if (x > WIDTH)
		return (0);
	if (y > HEIGHT)
		return (0);
	if (button == 4)
		fract->zoom = 1.2;
	else if (button == 5)
		fract->zoom = 0.8;
	else
		return (0);
	fract->min_re += (x_to_re(fract, x) - fract->min_re) * (1 - 1
			/ fract->zoom);
	fract->min_img += (y_to_img(fract, y) - fract->min_img) * (1 - 1
			/ fract->zoom);
	fract->max_re -= (fract->max_re - x_to_re(fract, x)) * (1 - 1
			/ fract->zoom);
	fract->max_img -= (fract->max_img - y_to_img(fract, y)) * (1 - 1
			/ fract->zoom);
	generate_fract(fract);
	return (0);
}

void	wasd_move(int keycode, t_fractal *fract)
{
	if (keycode == 115)
	{
		fract->min_img += (fract->max_img - fract->min_img) * 0.1;
		fract->max_img += (fract->max_img - fract->min_img) * 0.1;
	}
	else if (keycode == 119)
	{
		fract->min_img -= (fract->max_img - fract->min_img) * 0.1;
		fract->max_img -= (fract->max_img - fract->min_img) * 0.1;
	}
	else if (keycode == 100)
	{
		fract->min_re += (fract->max_re - fract->min_re) * 0.1;
		fract->max_re += (fract->max_re - fract->min_re) * 0.1;
	}
	else if (keycode == 97)
	{
		fract->min_re -= (fract->max_re - fract->min_re) * 0.1;
		fract->max_re -= (fract->max_re - fract->min_re) * 0.1;
	}
	generate_fract(fract);
}

int	key_pressed(int keycode, t_fractal *fract)
{
	if (keycode == 65307)
	{
		close_window2(fract);
	}
	if (keycode == 114)
	{
		initialise(fract);
		generate_fract(fract);
	}
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		wasd_move(keycode, fract);
	if (keycode == 99)
		change_color(fract);
	return (0);
}

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	t_fractal	*fract;

	fract = malloc(sizeof(t_fractal));
	ft_memset(fract, 0, sizeof(t_fractal));
	if (!fract)
		exit(EXIT_FAILURE);
	if (!check_parameters(argc, argv, fract))
		return (available_fractals(fract));
	mlx = mlx_init();
	if (!mlx)
		close_window_mlx_error(fract);
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, argv[1]);
	if (!mlx_win)
		close_window_display_error(fract, mlx);
	fract->mlx = mlx;
	fract->window = mlx_win;
	initialise(fract);
	generate_fract(fract);
	mlx_mouse_hook(fract->window, zoom, fract);
	mlx_key_hook(fract->window, key_pressed, fract);
	mlx_hook(fract->window, 17, 1, close_window2, fract);
	mlx_loop(mlx);
	return (0);
}
