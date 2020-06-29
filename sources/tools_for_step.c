/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 22:24:25 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/26 22:24:25 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_lenght_path(t_lem *lem, int k)
{
	int		i;
	int		am;

	i = 0;
	am = 0;
	while (i < lem->am->way)
	{
		if (k < lem->ant->len_way[i] + 1)
		{
			am++;
			return (am);
		}
		i++;
	}
	return (am);
}

int			count_previous_step(t_lem *lem, int step)
{
	int		i;
	int		am;

	i = 0;
	am = 0;
	while (lem->ant->step[step - 1][i])
	{
		if (lem->ant->step[step - 1][i] != lem->se->index_e)
			am++;
		i++;
	}
	return (am);
}

bool		check_ant_in_previous_step(t_lem *lem, int st, int j, int i)
{
	int		k;

	k = 0;
	while (lem->ant->step[st - 1][k])
	{
		if (lem->ant->step[st - 1][k] == lem->path[j][i - 1])
			return (true);
		k++;
	}
	return (false);
}

bool		is_ant_in_step(t_lem *lem, int st, int ant)
{
	int		i;

	i = 0;
	while (lem->ant->ant[st][i] != 0)
	{
		if ((lem->ant->ant[st][i] == ant) && (lem->ant->step[st][i]
		!= lem->se->index_e))
			return (true);
		i++;
	}
	return (false);
}
