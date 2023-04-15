/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:48:41 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/15 13:10:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*light_new(t_tuple position, t_color intensity)
{
	t_light	*p_light;

	p_light = malloc(sizeof(t_light));
	if (!p_light)
		return (NULL);
	p_light->position = position;
	p_light->intensity = intensity;
	p_light->next = NULL;
	return (p_light);
}

void	light_add(t_light **pl, t_light *new)
{
	t_light	*curr;

	if (!new)
		return ;
	if (!(*pl))
		*pl = new;
	else
	{
		curr = *pl;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	return ;
}

void	point_light_destroy(t_light **pl)
{
	t_light	*curr;

	while (*pl)
	{
		curr = (*pl)->next;
		free(*pl);
		*pl = curr;
	}
	return ;
}
