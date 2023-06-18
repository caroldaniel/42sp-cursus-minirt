/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:28:34 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/17 23:50:57 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_line	*validated(char *line);
static bool		is_line_parseble(char *line);
static bool		check_element(char *identifier);

void	parser(t_data *data)
{
	char	*line;
	t_line	*line_list;

	line_list = NULL;
	line = get_next_line(data->fd);
	while (line)
	{
		if (is_line_parseble(line))
			line_add(&line_list, validated(line));
		free(line);
		line = get_next_line(data->fd);
	}
	// int j = 0;
	// while (line_list)
	// {
	// 	printf("Line %d\n", ++j);
	// 	int i = -1;
	// 	while (line_list->tokens[++i])
	// 		printf("\t%s\n", line_list->tokens[i]);
	// 	printf("\t\ttotal count = %d\n", i);
	// 	line_list = line_list->next;
	// }
	// TODO: parse line_list
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

static bool	check_element(char *identifier)
{
	if (!ft_strncmp(identifier, "A", 2))
		return (true);
	if (!ft_strncmp(identifier, "C", 2))
		return (true);
	if (!ft_strncmp(identifier, "L", 2))
		return (true);
	if (!ft_strncmp(identifier, "sp", 3))
		return (true);
	if (!ft_strncmp(identifier, "pl", 3))
		return (true);
	if (!ft_strncmp(identifier, "cy", 3))
		return (true);
	if (!ft_strncmp(identifier, "cn", 3))
		return (true);
	return (false);
}
