/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_room_in_path.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:49:19 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:49:19 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			**copyy(t_lem *lem, int **new_path, int i)
{
	int		j;
	int		p;

	j = 0;
	p = 0;
	while (j < lem->am->way - 1)
	{
		if (j == i)
			p++;
		new_path[j] = int_copy(new_path[j], lem->path[p]);
		j++;
		p++;
	}
	return (new_path);
}

int			**copy_path(t_lem *lem, int **new_path, int i, int k)
{
	if (int_len(lem->path[i]) < int_len(lem->path[k]) ||
		int_len(lem->path[i]) == int_len(lem->path[k]))
		new_path = copyy(lem, new_path, k);
	else
		new_path = copyy(lem, new_path, i);
	return (new_path);
}

void		delete_path(t_lem *lem, int i, int k, t_path *pt)
{
	int		**new_path;

	new_path = init_new_path(lem, lem->am->way - 1);
	new_path = copy_path(lem, new_path, i, k);
	init_path(lem, lem->am->way - 1);
	i = 0;
	while (i < lem->am->way - 1)
	{
		lem->path[i] = int_copy(lem->path[i], new_path[i]);
		i++;
	}
	free_new_path(new_path, lem->am->way - 1);
	lem->am->way -= 1;
	if (pt->i != 0)
		pt->i -= 1;
	pt->j = pt->i + 1;
	pt->k = 0;
}

void		check_paths(t_lem *lem, t_path *pt)
{
	pt->i = 0;
	while (lem->path[pt->i] && pt->i < lem->am->way)
	{
		pt->j = pt->i + 1;
		while (lem->path[pt->j] && pt->j < lem->am->way)
		{
			pt->k = 0;
			while (lem->path[pt->i][pt->k] && pt->j < lem->am->way)
			{
				pt->p = 0;
				while (lem->path[pt->j][pt->p] &&
				(lem->path[pt->i][pt->k] != lem->path[pt->j][pt->p]))
					pt->p++;
				if ((lem->path[pt->i][pt->k] == lem->path[pt->j][pt->p]) &&
					(lem->path[pt->i][pt->k] != lem->se->index_e))
					delete_path(lem, pt->i, pt->j, pt);
				pt->k++;
			}
			pt->j++;
		}
		pt->i++;
	}
}
