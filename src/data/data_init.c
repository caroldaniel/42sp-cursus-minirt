/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:21:21 by cado-car          #+#    #+#             */
/*   Updated: 2023/05/15 21:54:44 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		window_init(t_data *data);
static void		image_init(t_data *data);
static t_color	**grid_init(int width, int height);

void	data_init(t_data *data, char *file_path)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(data_destroy(data, ERR_MLXINIT));
	data->file_path = ft_strdup(file_path);
	window_init(data);
	image_init(data);
	world_init(data);
}

static void	window_init(t_data *data)
{
	data->win.x = IMG_X;
	data->win.y = IMG_Y;
	data->win.ptr = mlx_new_window(data->mlx_ptr, data->win.x, data->win.y, RT);
	return ;
}

static void	image_init(t_data *data)
{
	data->img.x = IMG_X;
	data->img.y = IMG_Y;
	data->img.ptr = mlx_new_image(data->mlx_ptr, data->img.x, data->img.y);
	data->img.data = (int *)mlx_get_data_addr(data->img.ptr, \
		&data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
	data->img.grid = grid_init(data->img.x, data->img.y);
	if (!data->img.grid)
		exit(data_destroy(data, ERR_IMGINIT));
	return ;
}

static t_color	**grid_init(int width, int height)
{
	t_color	**grid;
	int		y;

	grid = malloc(sizeof(t_color *) * height);
	if (!grid)
		return (NULL);
	y = -1;
	while (++y < height)
	{
		grid[y] = malloc(sizeof(t_color) * width);
		if (!grid[y])
			return (NULL);
		ft_bzero(grid[y], sizeof(t_color) * width);
	}
	return (grid);
}
