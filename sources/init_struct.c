/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:46:47 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:46:47 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem			*init_lem_in(void)
{
	t_lem		*lem;

	if (!(lem = (t_lem *)ft_memalloc((sizeof(t_lem)))))
		exit(0);
	lem->height = 0;
	lem->r = 1;
	lem->l = 0;
	lem->p = 0;
	lem->t = 0;
	lem->a = 1;
	lem->r_ant = 1;
	lem->an = 0;
	lem->fd = 0;
	return (lem);
}

t_se			*init_se(void)
{
	t_se		*se;

	if (!(se = (t_se *)ft_memalloc(sizeof(t_se))))
		exit(0);
	se->start = NULL;
	se->end = NULL;
	se->end_c_x = 0;
	se->end_c_y = 0;
	se->start_c_x = 0;
	se->start_c_y = 0;
	se->index_e = 0;
	se->index_s = 0;
	return (se);
}

t_room			*init_room(void)
{
	t_room		*room;

	if (!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		exit(0);
	room->c_x = 0;
	room->c_y = 0;
	room->name = NULL;
	room->name = NULL;
	room->flag = 0;
	room->len = 0;
	room->index = 0;
	return (room);
}

t_link			*init_link(void)
{
	t_link		*link;

	if (!(link = (t_link *)ft_memalloc(sizeof(t_link))))
		exit(0);
	return (link);
}

t_amount		*init_amount(void)
{
	t_amount	*am;

	if (!(am = (t_amount *)ft_memalloc(sizeof(t_amount))))
		exit(0);
	am->comment = 0;
	am->link = 0;
	am->room = 0;
	am->s = 0;
	am->e = 0;
	am->ant = 0;
	am->new_link = 0;
	am->step = 0;
	am->cmd = 0;
	return (am);
}
