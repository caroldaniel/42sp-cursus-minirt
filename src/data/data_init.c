/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:21:21 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/13 13:37:24 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	open_path(t_data *data, char *file_path);
static void	window_init(t_data *data);

void	data_init(t_data *data, char *file_path)
{
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
	return ;
}

static void	open_path(t_data *data, char *file_path)
{
	int	fd;
	int	path_len;

	data->file_path = ft_strdup(file_path);
	if (!data->file_path)
		exit(data_destroy(data, ERR_MEMALOC));
	path_len = ft_strlen(data->file_path);
	if (path_len <= 3 || ft_strncmp(file_path + path_len - 3, ".rt", 3))
		exit(data_destroy(data, ERR_EXTINVL));
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		exit(data_destroy(data, ERR_FDERROR));
	}
	//Include parser function here
	close(fd);
	return ;
}
