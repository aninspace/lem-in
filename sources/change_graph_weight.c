/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_graph_weight.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:34:38 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/26 19:34:38 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			change_graph_weight(t_lem *lem)
{
	int			i;

	i = 0;
	while (lem->ver->ver[i])
	{
		lem->mat[lem->ver->ver[i]][lem->ver->ver[i + 1]] = 1;
		lem->mat[lem->ver->ver[i + 1]][lem->ver->ver[i]] = 0;
		i++;
	}
	lem->mat[lem->ver->ver[i]][0] = 1;
	lem->mat[0][lem->ver->ver[i]] = 0;
}

void			null_graph(t_lem *lem)
{
	int			i;
	int			k;

	i = 0;
	while (i < lem->am->room)
	{
		k = i + 1;
		while (k < lem->am->room)
		{
			lem->mat[i][k] = 0;
			lem->mat[k][i] = 0;
			k++;
		}
		i++;
	}
}

void			null_one_way(t_lem *lem)
{
	int			i;

	i = 0;
	lem->mat[0][lem->path[lem->p][i]] = 0;
	while (lem->path[lem->p][i + 1])
	{
		lem->mat[lem->path[lem->p][i]][lem->path[lem->p][i + 1]] = 0;
		i++;
	}
}

void			connect_ways(t_lem *lem, t_ver *ver)
{
	int			i;

	while (ver->next != NULL)
	{
		i = 0;
		while (ver->ver[i])
		{
			lem->mat[ver->ver[i + 1]][ver->ver[i]] = 1;
			i++;
		}
		lem->mat[ver->ver[i]][0] = 1;
		ver = ver->next;
	}
}
