/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:28:34 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 09:32:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_line	*validated(char *line);
static bool		is_line_parseble(char *line);

void	parser(t_data *data)
{
	char	*line;
	t_line	*line_list;

	line_list = NULL;
	line = get_next_line(data->fd);
	while (line)
	{
		if (is_line_parseble(line))
		{
			if (!validated(line))
			{
				line_list_destroy(line_list);
				exit(data_destroy(data, ERR_INVELEM));
			}
			line_add(&line_list, validated(line));
		}
		free(line);
		line = get_next_line(data->fd);
	}
	if (!check_count(line_list))
		exit(data_destroy(data, ERR_SCNCNTR));
	get_element_properties(line_list, data);
	line_list_destroy(line_list);
	return ;
}

static t_line	*validated(char *line)
{
	t_line	*new;

	new = line_new(line);
	if (!new)
		return (NULL);
	if (!check_element(new->tokens[0]))
		line_destroy(&new);
	if (!check_element_properties_count(new))
		line_destroy(&new);
	return (new);
}

static bool	is_line_parseble(char *line)
{
	if (!line)
		return (false);
	if (line[0] == '\n')
		return (false);
	if (line[0] == '\0')
		return (false);
	if (line[0] == '#')
		return (false);
	if (ft_strlen(line) >= 2 && line[0] == '/' && line[1] == '/')
		return (false);
	return (true);
}
