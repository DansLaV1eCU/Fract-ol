/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:23:53 by llupache          #+#    #+#             */
/*   Updated: 2025/07/18 17:36:38 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "libft/includes/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 180
# define WIDTH 320
# define MAX_ITERATIONS 100

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_image;

typedef struct t_fractal
{
	int		x;
	int		y;
	double	y_c;
	double	x_c;
	double	min_re;
	double	max_re;
	double	min_img;
	double	max_img;
	double	max_norm;
	void	*mlx;
	void	*window;
	double	zoom;
	char	*name;
	int		color;
	t_image	*im_fr;
}			t_fractal;

void		generate_fract(t_fractal *fract);
void		julia_generate(t_fractal *fract);
void		burning_ship_generate(t_fractal *fract);
void		mandelbrot_generate(t_fractal *fract);
void		initialise(t_fractal *fract);
int			check_parameters(int argc, char **argv, t_fractal *fract);
void		put_pixel_to_image(t_fractal *fract, int color);
double		x_to_re(t_fractal *fract, int x);
double		y_to_img(t_fractal *fract, int y);
int			norm(double x, double y);
void		change_color(t_fractal *fract);
double		string_to_double(const char *str);
void		put_strings(t_fractal *fract);
int			close_window_mlx_error(t_fractal *fract);
int			close_window_display_error(t_fractal *fract, void *mlx);
int			close_window2(t_fractal *fract);
int			available_fractals(t_fractal *fract);
void		generate_fract_2(t_fractal *fract);

#endif
