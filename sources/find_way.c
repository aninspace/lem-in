/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:47:42 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:47:42 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			find_way(t_lem *lem, int r)
{
	int		i;
	int		k;
	int		j;

	j = 0;
	i = 0;
	while (j < lem->am->room)
	{
		k = 1;
		while ((!(lem->mat[i][k] == 1 && lem->mat[k][i] == 0)) && k < r)
			k++;
		if (lem->mat[i][k] == 1 && lem->mat[k][i] == 0)
			lem->path[lem->p][j] = k;
		j++;
		if (k == lem->se->index_e + 1)
			break ;
		i = 1;
		while ((!(lem->mat[k][i] == 1 && lem->mat[i][k] == 0)) && i < r)
			i++;
		if (lem->mat[k][i] == 1 && lem->mat[i][k] == 0)
			lem->path[lem->p][j] = i;
		j++;
		if (i == lem->se->index_e + 1)
			break ;
	}
}
