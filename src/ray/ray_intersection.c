/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:08:16 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/15 12:00:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_x	*x_new(t_object *object, double t)
{
	t_x	*x;

	x = malloc(sizeof(t_x));
	if (!x)
		return (NULL);
	x->object = object;
	x->t = t;
	x->next = NULL;
	return (x);
}

void	x_list_add(t_x **xl, t_x *new)
{
	t_x	*curr;

	if (!new)
		return ;
	if (!(*xl) || (*xl)->t >= new->t)
	{
		new->next = (*xl);
		(*xl) = new;
		return ;
	}
	curr = (*xl);
	while (curr->next && new->t > curr->next->t)
		curr = curr->next;
	new->next = curr->next;
	curr->next = new;
	return ;
}	

void	x_list_destroy(t_x **xl)
{
	t_x	*curr;

	while (*xl)
	{
		curr = (*xl);
		(*xl) = (*xl)->next;
		free(curr);
	}
}

t_x	*x_list_copy(t_x *original)
{
	t_x	*copy;
	t_x	*curr;

	if (!original)
		return (NULL);
	copy = NULL;
	curr = original;
	while (curr)
	{
		x_list_add(&copy, x_new(curr->object, curr->t));
		curr = curr->next;
	}
	return (copy);
}

t_x	*hit(t_ray *ray)
{
	t_x	*curr;

	curr = ray->x_list;
	while (curr)
	{
		if (curr->t < 0)
		{
			curr = curr->next;
			continue ;
		}
		return (curr);
	}
	return (NULL);
}
