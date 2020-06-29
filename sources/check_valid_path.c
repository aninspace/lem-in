/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 00:59:39 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/26 00:59:53 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		**copy_path1(t_lem *lem, int **new_path, int i)
{
	int		p;
	int		j;

	p = 0;
	j = 0;
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

void	delete_path1(t_lem *lem, int i)
{
	int		**new_path;

	new_path = init_new_path(lem, lem->am->way - 1);
	new_path = copy_path1(lem, new_path, i);
	i = 0;
	init_path(lem, lem->am->way - 1);
	i = 0;
	while (i < lem->am->way - 1)
	{
		lem->path[i] = int_copy(lem->path[i], new_path[i]);
		i++;
	}
	free_new_path(new_path, lem->am->way - 1);
	lem->am->way -= 1;
}

void	check_valid(t_lem *lem)
{
	int		i;
	int		k;

	i = 0;
	while (i < lem->am->way)
	{
		k = 0;
		while (lem->path[i][k] != 0)
			k++;
		if (lem->path[i][k - 1] != lem->se->index_e)
		{
			delete_path1(lem, i);
			i -= 1;
		}
		i++;
	}
}
