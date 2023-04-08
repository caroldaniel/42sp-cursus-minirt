/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:21:21 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/07 21:28:14 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	***init_grid(int width, int height);

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
}

static t_color	***init_grid(int width, int height)
{
	t_color	***grid;
	int		i;

	grid = malloc(sizeof(t_color **) * width);
	if (!grid)
		return (NULL);
	i = -1;
	while (++i < width)
	{
		grid[i] = malloc(sizeof(t_color *) * height);
		if (!grid[i])
			return (NULL);
	}
	return (grid);
}
