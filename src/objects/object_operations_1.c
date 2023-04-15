/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:49:57 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/15 11:38:12 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform(t_object *object, t_matrix t)
{
	matrix_destroy(&object->transform);
	object->transform = t;
}
