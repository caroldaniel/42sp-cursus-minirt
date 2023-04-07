/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:58:45 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/07 00:18:26 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	close_window(t_data *data);
static int	key_handle(int keycode, t_data *data);

void	set_hooks(t_data *data)
{
    mlx_hook(data->mlx_win, DESTROY_NOTIFY, 1L, close_window, data);
	mlx_key_hook(data->mlx_win, key_handle, data);
	return ;
}

static int	close_window(t_data *data)
{
	exit(data_destroy(data, 0));
	return (0);
}

static int	key_handle(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit(data_destroy(data, 0));
	return (0);
}
