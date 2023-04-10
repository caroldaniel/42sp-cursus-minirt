/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:59:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/09 23:04:23 by cado-car         ###   ########.fr       */
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
	m = matrix_populate(3, 1.0, 2.0, 6.0, \
		-5.0, 8.0, -4.0, \
		2.0, 6.0, 4.0);
	print_matrix(m);
	printf("cofactor(A, 0, 0) = %.2f\n", cofactor(m, 0, 0));
	printf("cofactor(A, 0, 1) = %.2f\n", cofactor(m, 0, 1));
	printf("cofactor(A, 0, 2) = %.2f\n", cofactor(m, 0, 2));
	printf("determinant(A) = %.2f\n", determinant(m));
	t = matrix_populate(4, -2.0, -8.0, 3.0, 5.0, \
		-3.0, 1.0, 7.0, 3.0, \
		1.0, 2.0, -9.0, 6.0, \
		-6.0, 7.0, 7.0, -9.0);
	print_matrix(t);
	printf("cofactor(B, 0, 0) = %.2f\n", cofactor(t, 0, 0));
	printf("cofactor(B, 0, 1) = %.2f\n", cofactor(t, 0, 1));
	printf("cofactor(B, 0, 2) = %.2f\n", cofactor(t, 0, 2));
	printf("cofactor(B, 0, 3) = %.2f\n", cofactor(t, 0, 3));
	printf("determinant(B) = %.2f\n", determinant(t));
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
