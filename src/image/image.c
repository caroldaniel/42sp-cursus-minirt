/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:54:58 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 13:38:03 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	**grid_init(int width, int height);

void	image_init(t_data *data)
{
	data->img.ptr = mlx_new_image(data->mlx_ptr, data->img.x, data->img.y);
	if (!data->img.ptr)
		exit(data_destroy(data, ERR_IMGINIT));
	data->img.data = (int *)mlx_get_data_addr(data->img.ptr, \
		&data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
	if (!data->img.data)
		exit(data_destroy(data, ERR_IMGINIT));
	data->img.grid = grid_init(data->img.x, data->img.y);
	if (!data->img.grid)
		exit(data_destroy(data, ERR_MEMALOC));
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
		{
			while (--y > -1)
				free(grid[y]);
			return (NULL);
		}
		ft_bzero(grid[y], sizeof(t_color) * width);
	}
	return (grid);
}
