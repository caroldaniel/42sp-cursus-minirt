/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:44:03 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 22:38:25 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	float_cmp(float a, float b, float epsilon)
{
	if (abs_float(a - b) < epsilon)
		return (TRUE);
	else
		return (FALSE);
}
