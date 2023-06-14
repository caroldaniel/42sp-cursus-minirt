/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:44:03 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/05 10:36:56 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	comp(double a, double b, double epsilon)
{
	if (fabs(a - b) < epsilon)
		return (true);
	else
		return (false);
}
