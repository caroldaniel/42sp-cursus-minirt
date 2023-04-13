/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:59:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/12 22:14:37 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	draw_on_grid(t_data *data);

void	image_create(t_data *data)
{
	int			s;
	t_x			*i[4];
	t_x_list	xl;
	t_x			*h;

	image_init(data);
	draw_on_grid(data);
	s = sphere();
	i[0] = intersection(s, 5);
	i[1] = intersection(s, 7);
	i[2] = intersection(s, -3);
	i[3] = intersection(s, 2);
	xl = x_list_init();
	h = hit(*x_list(&xl, 4, i[0], i[1], i[2], i[3]));
	if (!h)
		printf("No hits found!\n");
	else
		printf("hit = %.2f\n", h->t);
	image_generate(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}

static void	draw_on_grid(t_data *data)
{
	t_tuple		hour;
	t_matrix	rot;
	t_color		c;
	int			i;

	hour = point(0, 200, 0);
	rot = rotation_z(M_PI / 6);
	c = color(1, 1, 1, 1);
	i = -1;
	while (++i < 12)
	{
		hour = matrix_tuple_multiply(rot, hour);
		put_pixel(data->img, hour.x, hour.y, c);
	}
	matrix_destroy(&rot);
}
