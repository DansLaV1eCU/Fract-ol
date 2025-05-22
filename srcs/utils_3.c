/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:48:07 by llupache          #+#    #+#             */
/*   Updated: 2025/05/22 20:24:44 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	generate_fract_2(t_fractal *fract)
{
	while (fract->y < HEIGHT)
	{
		fract->x = 0;
		while (fract->x < WIDTH)
		{
			if (ft_strncmp(fract->name, "Julia", 6) == 0)
				julia_generate(fract);
			else if (ft_strncmp(fract->name, "Mandelbrot", 11) == 0)
				mandelbrot_generate(fract);
			else if (ft_strncmp(fract->name, "Burning_ship", 6) == 0)
				burning_ship_generate(fract);
			fract->x++;
		}
		fract->y++;
	}
}

int	available_fractals(t_fractal *fract)
{
	free(fract);
	ft_printf("Available fractals:\n-Julia Re Img \
		\n-Mandelbrot\n-Burning_ship\n");
	exit(0);
}

int	close_window_mlx_error(t_fractal *fract)
{
	free(fract);
	exit(EXIT_FAILURE);
}

int	close_window_display_error(t_fractal *fract, void *mlx)
{
	mlx_destroy_display(mlx);
	free(fract);
	exit(EXIT_FAILURE);
}

int	close_window2(t_fractal *fract)
{
	mlx_destroy_window(fract->mlx, fract->window);
	if (fract->im_fr)
	{
		mlx_destroy_image(fract->mlx, fract->im_fr->img);
		free(fract->im_fr);
	}
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	free(fract);
	exit(0);
}
