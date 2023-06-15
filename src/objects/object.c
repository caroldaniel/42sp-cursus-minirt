/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:23:17 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 23:31:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*object_new(int type, int id)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = type;
	new->id = id;
	new->transform = identity(4);
	new->material = material();
	new->minimum = 0;
	new->maximum = 0;
	new->capped = false;
	new->next = NULL;
	return (new);
}

void	object_add(t_object **ol, t_object *new)
{
	t_object	*curr;

	if (!new)
		return ;
	if (!(*ol))
		*ol = new;
	else
	{
		curr = *ol;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	return ;
}

void	object_list_destroy(t_object**ol)
{
	t_object	*curr;

	while (*ol)
	{
		curr = (*ol)->next;
		if ((*ol)->transform.data)
			matrix_destroy(&(*ol)->transform);
		if ((*ol)->material.pattern.transform.data)
			matrix_destroy(&(*ol)->material.pattern.transform);
		free(*ol);
		*ol = curr;
	}
	return ;
}
