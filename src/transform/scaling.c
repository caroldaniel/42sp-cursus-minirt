/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:15:30 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/10 16:45:41 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	scaling(double x, double y, double z)
{
	t_matrix	s;

	s = identity(4);
	if (!s.size)
		return (s);
	s.data[0][0] = x;
	s.data[1][1] = y;
	s.data[2][2] = z;	
	return (s);
}
