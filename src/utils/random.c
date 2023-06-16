/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:52:27 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/15 22:11:02 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	random_nb(void)
{
	int				fd;
	unsigned int 	random_data;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (0);
	if (read(fd, &random_data, sizeof(random_data)) == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return ((double)random_data / (double)UINT_MAX);
}
