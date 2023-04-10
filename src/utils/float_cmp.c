/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:44:03 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/10 15:04:37 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	float_cmp(double a, double b, double epsilon)
{
	if (abs_float(a - b) < epsilon)
		return (true);
	else
		return (false);
}
