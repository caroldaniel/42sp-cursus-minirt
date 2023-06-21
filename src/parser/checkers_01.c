/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:15:10 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 12:38:52 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_counter	counter_init(void);
static void			count_element(t_line *line, t_counter *counter);
static bool			check_element_count(t_counter counter);

bool	check_count(t_line *line)
{
	t_counter	counter;

	counter = counter_init();
	while (line)
	{
		count_element(line, &counter);
		line = line->next;
	}
	return (check_element_count(counter));
}

static t_counter	counter_init(void)
{
	t_counter	counter;

	counter.ratio.count = 0;
	counter.ratio.locked = false;
	counter.ambient.count = 0;
	counter.ambient.locked = false;
	counter.camera.count = 0;
	counter.camera.locked = false;
	counter.light.count = 0;
	counter.light.locked = false;
	counter.plane.count = 0;
	counter.plane.locked = false;
	counter.sphere.count = 0;
	counter.sphere.locked = false;
	counter.cylinder.count = 0;
	counter.cylinder.locked = false;
	counter.cone.count = 0;
	counter.cone.locked = false;
	return (counter);
}

static void	count_element(t_line *line, t_counter *counter)
{
	t_element	*element;
	char		*identifier;

	identifier = line->tokens[0];
	if (comp_str(identifier, "R"))
		element = &counter->ratio;
	if (comp_str(identifier, "A"))
		element = &counter->ambient;
	if (comp_str(identifier, "C"))
		element = &counter->camera;
	if (comp_str(identifier, "L"))
		element = &counter->light;
	if (comp_str(identifier, "sp"))
		element = &counter->sphere;
	if (comp_str(identifier, "pl"))
		element = &counter->plane;
	if (comp_str(identifier, "cy"))
		element = &counter->cylinder;
	if (comp_str(identifier, "cn"))
		element = &counter->cone;
	element->count++;
	if (*identifier >= 'A' && *identifier <= 'Z')
		element->locked = true;
}

static bool	check_element_count(t_counter counter)
{
	if (counter.ratio.count > 1)
		return (false);
	if (!counter.camera.locked || counter.camera.count != 1)
		return (false);
	if (counter.ambient.locked && counter.ambient.count > 1)
		return (false);
	if (counter.light.locked && counter.light.count > 1)
		return (false);
	if (counter.plane.locked && counter.plane.count > 1)
		return (false);
	if (counter.sphere.locked && counter.sphere.count > 1)
		return (false);
	if (counter.cylinder.locked && counter.cylinder.count > 1)
		return (false);
	if (counter.cone.locked && counter.cone.count > 1)
		return (false);
	if (counter.ambient.count + counter.light.count == 0)
		return (false);
	if (counter.sphere.count + counter.plane.count + counter.cylinder.count
		+ counter.cone.count == 0)
		return (false);
	return (true);
}

bool	check_element(char *identifier)
{
	if (!ft_strncmp(identifier, "R", 2))
		return (true);
	if (!ft_strncmp(identifier, "C", 2))
		return (true);
	if (comp_str(identifier, "A"))
		return (true);
	if (comp_str(identifier, "L"))
		return (true);
	if (comp_str(identifier, "sp"))
		return (true);
	if (comp_str(identifier, "pl"))
		return (true);
	if (comp_str(identifier, "cy"))
		return (true);
	if (comp_str(identifier, "cn"))
		return (true);
	return (false);
}
