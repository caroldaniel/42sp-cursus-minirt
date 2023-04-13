/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:08:16 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/12 23:16:30 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_x	*intersection(t_object object, double t)
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

t_x_list	x_list_init(void)
{
	t_x_list	xl;

	xl.count = 0;
	xl.list = NULL;
	return (xl);
}

t_x_list	x_list(t_x_list *xl, int count, ...)
{
	va_list	args;
	t_x		*inter;
	int		i;

	if (!count)
		return (*xl);
	va_start(args, count);
	i = -1;
	while (++i < count)
	{
		inter = va_arg(args, t_x *);
		x_list_add(xl, inter);
	}
	va_end(args);
	return (*xl);
}

void	x_list_add(t_x_list *xl, t_x *new)
{
	t_x	*curr;

	if (!xl || !new)
		return ;
	if (!xl->list || xl->list->t >= new->t)
	{
		new->next = xl->list;
		xl->list = new;
	}
	else
	{
		curr = xl->list;
		while (curr->next && new->t > curr->next->t)
			curr = curr->next;
		new->next = curr->next;
		curr->next = new;
	}
	xl->count++;
}	

void	x_list_destroy(t_x_list *xl)
{
	t_x	*curr;

	xl->count = 0;
	while (xl->list)
	{
		curr = xl->list;
		xl->list = xl->list->next;
		free(curr);
	}
}
