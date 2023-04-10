/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:36:47 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/10 19:24:37 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	translation(double x, double y, double z)
{
	t_matrix	t;

	t = identity(4);
	if (!t.size)
		return (t);
	t.data[0][3] = x;
	t.data[1][3] = y;
	t.data[2][3] = z;
	return (t);
}
