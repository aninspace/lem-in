/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:47:15 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:47:15 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_se(t_lem *lem)
{
	free(lem->se->start);
	free(lem->se->end);
	free(lem->se);
	lem->se = NULL;
}

void	free_lem_in(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->am->way)
	{
		free(lem->path[i]);
		i++;
	}
	free(lem->path);
	free(lem->am);
	free(lem->d);
	free(lem->new_ver);
	free(lem->pt);
	lem->am = NULL;
	free(lem->map);
	lem->map = NULL;
	free(lem);
}

void	free_room(t_lem *lem)
{
	t_room *tmp;
	t_room *next;

	tmp = lem->room;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp->name);
		free(tmp);
		tmp = next;
	}
	tmp = NULL;
}

void	free_link(t_lem *lem)
{
	t_link *tmp;
	t_link *next;

	tmp = lem->link;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp->start);
		free(tmp->end);
		free(tmp);
		tmp = next;
	}
	tmp = NULL;
}

void	free_remember(t_lem *lem)
{
	int	i;

	i = 0;
	while (i < 100000)
	{
		free(lem->remember[i]);
		i++;
	}
	free(lem->remember);
}
