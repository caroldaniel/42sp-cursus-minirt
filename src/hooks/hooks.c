/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:58:45 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/24 21:20:35 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	handle_close(t_data *data);
static int	handle_expose(t_data *data);
static int	handle_key(int keycode, t_data *data);

void	set_hooks(t_data *data)
{
	mlx_hook(data->win.ptr, DESTROY_NOTIFY, 0L, handle_close, data);
	mlx_key_hook(data->win.ptr, handle_key, data);
	mlx_expose_hook(data->win.ptr, handle_expose, data);
	return ;
}

static int	handle_close(t_data *data)
{
	exit(data_destroy(data, 0));
	return (0);
}

static int	handle_expose(t_data *data)
{
	image_display(data);
	return (0);
}

static int	handle_key(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit(data_destroy(data, 0));
	return (0);
}
