/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:58:45 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/06 18:27:10 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	key_handle(int keycode, t_data *data);

void	set_hooks(t_data *data)
{
	mlx_key_hook(data->mlx_win, &key_handle, data);
	return ;
}

static int	key_handle(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit(data_destroy(data, 0));
	return (0);
}
