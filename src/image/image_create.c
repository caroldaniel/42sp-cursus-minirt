/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:59:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/08 18:27:13 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	draw_on_grid(t_data *data);
static void	draw_line(t_data *data, t_coord a, t_coord b, t_color c);

void	image_create(t_data *data)
{
	image_init(data);
	draw_on_grid(data);
	image_generate(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}

static void	draw_on_grid(t_data *data)
{
	t_matrix	m;
	t_matrix	t;
	t_coord		a;
	t_coord		b;

	a = coordinate(10, 10);
	b = coordinate(490, 490);
	draw_line(data, a, b, color(1, 1, 1, 1));
	m = matrix_populate(4, 1.0, 2.0, 3.0, 4.0, \
		2.0, 4.0, 4.0, 2.0, \
		8.0, 6.0, 4.0, 1.0, \
		0.0, 0.0, 0.0, 1.0);
	print_matrix(m);
	t = matrix_transpose(m);
	print_matrix(t);
	matrix_destroy(&m);
	matrix_destroy(&t);
}

static void	draw_line(t_data *data, t_coord a, t_coord b, t_color c)
{
	int		dx;
	int		dy;
	float	slope;
	int		y_intercept;
	int		i;

	dx = b.x - a.x;
	dy = b.y - a.y;
	slope = (float)(dy / dx);
	y_intercept = a.y - slope * a.x;
	i = a.x - 1;
	while (++i <= b.x)
		put_pixel(data->img, i, slope * i + y_intercept, c);
}
