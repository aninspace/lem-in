/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_deixtra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:50:01 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:50:24 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_weight(t_lem *lem, int i, int k, int end)
{
	lem->weight = lem->dist;
	end = i;
	lem->ver->ver[k] = i;
	return (end);
}

void	recovery_way(t_lem *lem, int *d)
{
	int		end;
	int		k;
	int		i;

	end = lem->se->index_e;
	k = 1;
	lem->weight = d[end];
	lem->ver->ver[0] = end;
	while (end != 0)
	{
		i = 0;
		while (i < lem->am->room)
		{
			if (lem->mat[i][end] != 0)
			{
				lem->dist = lem->weight - lem->mat[i][end];
				if (lem->dist == d[i])
				{
					end = check_weight(lem, i, k, end);
					k++;
				}
			}
			i++;
		}
	}
}

void	init_arrays(t_lem *lem)
{
	int begin_index;
	int i;

	i = 0;
	begin_index = 0;
	if (!lem->d)
		lem->d = (int *)malloc(sizeof(int) * (lem->am->room + 1));
	lem->v = (int *)malloc(sizeof(int) * (lem->am->room + 1));
	lem->ver->ver = (int *)malloc(sizeof(int) * (lem->am->room + 1));
	while (i < lem->am->room)
	{
		lem->d[i] = INT_MAX;
		lem->v[i] = 1;
		i++;
	}
	lem->d[begin_index] = 0;
}

void	calc_distance(t_lem *lem, int minindex, int min)
{
	int		i;
	int		dist;

	if (minindex != INT_MAX)
	{
		i = 0;
		while (i < lem->am->room)
		{
			if (lem->mat[minindex][i] > 0)
			{
				dist = min + lem->mat[minindex][i];
				if (dist < lem->d[i])
					lem->d[i] = dist;
			}
			i++;
		}
		lem->v[minindex] = 0;
	}
}

bool	algo_deixtra(t_lem *lem)
{
	int		minindex;
	int		min;
	int		i;

	minindex = 0;
	init_arrays(lem);
	while (minindex < INT_MAX)
	{
		minindex = INT_MAX;
		min = INT_MAX;
		i = 0;
		while (i < lem->am->room)
		{
			if (lem->v[i] == 1 && lem->d[i] < min)
			{
				min = lem->d[i];
				minindex = i;
			}
			i++;
		}
		calc_distance(lem, minindex, min);
	}
	free(lem->v);
	return (true);
}
