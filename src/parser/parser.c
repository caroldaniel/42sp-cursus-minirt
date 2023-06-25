/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:28:34 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/25 19:01:20 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_line	*validated(char *line);
static bool		is_line_parseble(char *line);
static void		finish_reading(int fd, char **line);

void	parser(t_data *data)
{
	char	*line;
	t_line	*curr;

	data->line_list = NULL;
	curr = NULL;
	line = get_next_line(data->fd);
	while (line)
	{
		if (is_line_parseble(line))
		{
			curr = validated(line);
			if (!curr)
			{
				finish_reading(data->fd, &line);
				exit(data_destroy(data, ERR_INVELEM));
			}
			line_add(&data->line_list, curr);
		}
		free(line);
		line = get_next_line(data->fd);
	}
	if (!check_count(data->line_list))
		exit(data_destroy(data, ERR_SCNCNTR));
	get_element_properties(data->line_list, data);
	return ;
}

static t_line	*validated(char *line)
{
	t_line	*new;

	new = line_new(line);
	if (!new)
		return (NULL);
	if (!check_element(new->tokens[0]) || !check_element_properties_count(new))
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

static void	finish_reading(int fd, char **line)
{
	while (*line)
	{
		free(*line);
		*line = get_next_line(fd);
	}
	return ;
}
