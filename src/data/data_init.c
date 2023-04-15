/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:21:21 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/15 12:45:23 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	**init_grid(int width, int height);

void	data_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(data_destroy(data, ERR_MLXINIT));
	data->win_ptr = mlx_new_window(data->mlx_ptr, IMG_X, IMG_Y, MINIRT);
	data->img.ptr = mlx_new_image(data->mlx_ptr, IMG_X, IMG_Y);
	data->img.data = (int *)mlx_get_data_addr(data->img.ptr, \
		&data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
	data->img.grid = init_grid(IMG_X, IMG_Y);
	if (!data->img.grid)
		exit(data_destroy(data, ERR_IMGINIT));
	data->world = world_init();
}

static t_color	**init_grid(int width, int height)
{
	t_color	**grid;
	int		y;

	grid = malloc(sizeof(t_color *) * height);
	if (!grid)
		return (NULL);
	y = -1;
	while (++y < width)
	{
		grid[y] = malloc(sizeof(t_color) * width);
		if (!grid[y])
			return (NULL);
		ft_bzero(grid[y], sizeof(t_color) * width);
	}
	return (grid);
}
