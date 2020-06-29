/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <Student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:54:25 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:54:25 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		init_begin(t_lem *lem, t_room *room)
{
	int		b;

	b = -1;
	if (room->name && ft_strcmp(lem->link->start, room->name) == 0)
		b = room->index;
	if (ft_strcmp(lem->link->start, lem->se->start) == 0)
		b = lem->se->index_s;
	if (ft_strcmp(lem->link->start, lem->se->end) == 0)
		b = lem->se->index_e;
	return (b);
}

int		init_end(t_lem *lem, t_room *room)
{
	int		e;

	e = -1;
	if (room->name && ft_strcmp(lem->link->end, room->name) == 0)
		e = room->index;
	if (ft_strcmp(lem->link->end, lem->se->start) == 0)
		e = lem->se->index_s;
	if (ft_strcmp(lem->link->end, lem->se->end) == 0)
		e = lem->se->index_e;
	return (e);
}

void	init_struct_path(t_lem *lem)
{
	if (!(lem->pt = (t_path *)ft_memalloc(sizeof(t_path))))
		exit(EXIT_FAILURE);
}

t_lem	*full_init(void)
{
	t_lem	*lem;

	lem = init_lem_in();
	lem->am = init_amount();
	lem->room = init_room();
	lem->link = init_link();
	lem->se = init_se();
	lem->ver = init_ver();
	return (lem);
}
