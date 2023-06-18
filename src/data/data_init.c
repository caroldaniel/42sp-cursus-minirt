/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:21:21 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/17 21:36:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	open_path(t_data *data, char *file_path);
static void	window_init(t_data *data);

void	data_init(t_data *data, char *file_path)
{
	data->fd = -1;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(data_destroy(data, ERR_MLXINIT));
	window_init(data);
	image_init(data);
	world_init(data);
	open_path(data, file_path);
}

static void	window_init(t_data *data)
{
	data->win.x = IMG_X;
	data->win.y = IMG_Y;
	data->win.ptr = mlx_new_window(data->mlx_ptr, data->win.x, data->win.y, RT);
	if (data->win.ptr == NULL)
		exit(data_destroy(data, ERR_MLXINIT));
	return ;
}

static void	open_path(t_data *data, char *file_path)
{
	int	path_len;

	data->fd = open(file_path, O_RDONLY);
	if (data->fd < 0)
		exit(data_destroy(data, ERR_FDERROR));
	path_len = ft_strlen(file_path);
	if (path_len <= 3 || ft_strncmp(file_path + path_len - 3, ".rt", 3))
		exit(data_destroy(data, ERR_EXTINVL));
	parser(data);
	data->fd = close(data->fd);
	return ;
}
