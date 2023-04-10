/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:59:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/10 15:01:30 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	draw_on_grid(t_data *data);
static void	draw_line(t_data *data, t_coord a, t_coord b, t_color c);
static void	calculate_matrix(void);

void	image_create(t_data *data)
{
	image_init(data);
	draw_on_grid(data);
	calculate_matrix();
	image_generate(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}

static void	draw_on_grid(t_data *data)
{
	t_coord		a;
	t_coord		b;

	a = coordinate(10, 10);
	b = coordinate(490, 490);
	draw_line(data, a, b, color(1, 1, 1, 1));
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

static void	calculate_matrix(void)
{
	t_matrix	a;
	t_matrix	b;
	t_matrix	c;
	t_matrix	inv;
	t_matrix	c_inv;

	a = matrix_populate(4, \
	3.0, -9.0, 7.0, 3.0, \
	3.0, -8.0, 2.0, -9.0, \
	-4.0, 4.0, 4.0, 1.0, \
	-6.0, 5.0, -1.0, 1.0 \
	);
	b = matrix_populate(4, \
	8.0, 2.0, 2.0, 2.0, \
	3.0, -1.0, 7.0, 0.0, \
	7.0, 0.0, 5.0, 4.0, \
	6.0, -2.0, 0.0, 5.0 \
	);
	c = matrix_multiply(a, b);
	print_matrix(a);
	print_matrix(b);
	print_matrix(c);
	inv = matrix_inverse(b);
	c_inv = matrix_multiply(c, inv);
	print_matrix(inv);
	print_matrix(c_inv);
	if (matrix_compare(c_inv, a) == true)
		printf("Inversion is working\n");
	matrix_destroy(&a);
	matrix_destroy(&b);
	matrix_destroy(&c);
	matrix_destroy(&inv);
	matrix_destroy(&c_inv);
}
