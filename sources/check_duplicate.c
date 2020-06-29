/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:49:38 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:49:38 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool		check_link_duplicate(t_link *link)
{
	t_link *tmp;

	tmp = link;
	while (tmp->next != NULL)
	{
		link = tmp->next;
		while (link->next != NULL && (ft_strcmp(tmp->start, link->start) != 0 ||
				ft_strcmp(tmp->end, link->end) != 0))
			link = link->next;
		if (link->start != NULL && ft_strcmp(tmp->start, link->start) == 0 &&
				ft_strcmp(tmp->end, link->end) == 0)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool		check_link_reserve_duplicate(t_link *link)
{
	t_link	*tmp;

	tmp = link;
	while (tmp->next != NULL)
	{
		link = tmp->next;
		while (link->next != NULL && (ft_strcmp(tmp->end, link->start) != 0 ||
				ft_strcmp(tmp->start, link->end) != 0))
		{
			link = link->next;
		}
		if (link->start != NULL && ft_strcmp(tmp->end, link->start) == 0 &&
				ft_strcmp(tmp->start, link->end) == 0)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool		check_dupl_coord(t_lem *lem, t_room *room)
{
	t_room	*tmp;

	tmp = room;
	while (tmp->next != NULL)
	{
		room = tmp->next;
		while (room->next != NULL && ((tmp->c_x != room->c_x) ||
				(tmp->c_y != room->c_y)))
		{
			room = room->next;
		}
		if ((tmp->c_x == lem->se->start_c_x &&
			tmp->c_y == lem->se->start_c_y) ||
			(tmp->c_x == lem->se->end_c_x && tmp->c_y == lem->se->end_c_y))
		{
			return (false);
		}
		if (room->next != NULL &&
				(tmp->c_x == room->c_x) && (tmp->c_y == room->c_y))
		{
			return (false);
		}
		tmp = tmp->next;
	}
	return (true);
}

bool		check_name_duplicate(t_lem *lem, t_room *room)
{
	t_room	*tmp;

	tmp = room;
	while (tmp->next != NULL)
	{
		room = tmp->next;
		while (room->next != NULL && (ft_strcmp(tmp->name, room->name) != 0 ||
				ft_strcmp(tmp->name, lem->se->start) == 0 ||
				ft_strcmp(tmp->name, lem->se->end) == 0))
			room = room->next;
		if (ft_strcmp(tmp->name, lem->se->end) == 0 ||
			ft_strcmp(tmp->name, lem->se->start) == 0)
			return (false);
		if (room->next != NULL && (ft_strcmp(tmp->name, room->name) == 0))
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
