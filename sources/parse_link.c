/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:46:08 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:46:08 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			link_with_dashes(t_lem *lem, char *str, t_room *room)
{
	char		*dash_str;
	char		**split;

	dash_str = link_name_with_dashes(lem, room, str);
	split = ft_strsplit(dash_str, ' ');
	lem->room->next = NULL;
	lem->link->start = ft_strdup(split[0]);
	lem->link->end = ft_strdup(split[1]);
	ft_free_arr(split);
	free(dash_str);
}

void			all_links(t_lem *lem, char *str)
{
	char		**split;

	split = ft_strsplit(str, '-');
	lem->room->next = NULL;
	lem->link->start = ft_strdup(split[0]);
	lem->link->end = ft_strdup(split[1]);
	ft_free_arr(split);
}

bool			check_link(char *str, int dash)
{
	char		**split;

	split = ft_strsplit(str, ' ');
	if (len_arr(split) > 1)
	{
		ft_free_arr(split);
		return (false);
	}
	ft_free_arr(split);
	split = ft_strsplit(str, '-');
	if (len_arr(split) != 2 || dash == 0)
	{
		free(str);
		ft_free_arr(split);
		return (false);
	}
	ft_free_arr(split);
	return (true);
}

bool			match_link(t_lem *lem, t_room *room, t_room *tmp)
{
	int			b;
	int			e;

	while (room->next != NULL &&
		(ft_strcmp(lem->link->start, room->name) != 0) &&
		ft_strcmp(lem->link->start, lem->se->start) != 0 &&
		ft_strcmp(lem->link->start, lem->se->end) != 0)
		room = room->next;
	b = init_begin(lem, room);
	room = tmp;
	while (room->next != NULL &&
		(ft_strcmp(lem->link->end, room->name) != 0) && ft_strcmp(lem->link->end
		, lem->se->start) != 0 && ft_strcmp(lem->link->end, lem->se->end) != 0)
		room = room->next;
	e = init_end(lem, room);
	if (b == e || (b == -1 || e == -1))
		return (false);
	lem->mat[b][e] = 1;
	lem->mat[e][b] = 1;
	return (true);
}

bool			is_link(t_lem *lem, char *line, t_room *room)
{
	t_room	*tmp;
	int		dash;

	tmp = room;
	dash = how_many_dashes(line);
	if (!(check_link(line, dash)))
		return (false);
	if (dash > 1)
		link_with_dashes(lem, line, room);
	else
		all_links(lem, line);
	if (lem->am->link == 0)
	{
		init_mat(lem);
		lem->se->index_e = lem->am->room - 1;
	}
	if (!(match_link(lem, room, tmp)))
		return (false);
	lem->link->next = (t_link *)ft_memalloc(sizeof(t_link));
	lem->link = lem->link->next;
	return (true);
}
