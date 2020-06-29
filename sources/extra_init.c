/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:53:42 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:53:42 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ver	*init_ver(void)
{
	t_ver	*ver;

	if (!(ver = (t_ver *)malloc(sizeof(t_ver))))
		exit(EXIT_FAILURE);
	ver->ver = NULL;
	return (ver);
}

t_ant	*init_ant(t_lem *lem)
{
	t_ant	*ant;

	if (!(ant = (t_ant *)malloc(sizeof(t_ant))))
		exit(0);
	ant->c_len_way = NULL;
	ant->len_way = NULL;
	ant->step = NULL;
	ant->ant = NULL;
	ant->k = 0;
	ant->r_ant = 1;
	ant->a = 0;
	ant->i = 0;
	ant->an = lem->am->ant;
	ant->j = 0;
	ant->p = 0;
	return (ant);
}

void	init_change_lenght_way(t_lem *lem)
{
	int		i;
	int		p;

	i = 0;
	lem->ant->c_len_way = (int *)ft_memalloc(sizeof(int) * lem->am->way);
	while (i < lem->am->way)
	{
		if (i == 0)
			lem->ant->c_len_way[i] =
					lem->ant->len_way[i] - lem->ant->len_way[i];
		else if (i == 1)
			lem->ant->c_len_way[i] =
					lem->ant->len_way[i] - lem->ant->len_way[i - 1];
		else
		{
			p = i - 1;
			while (p >= 0)
			{
				lem->ant->c_len_way[i] +=
						lem->ant->len_way[i] - lem->ant->len_way[p];
				p--;
			}
		}
		i++;
	}
}

void	init_lenght_way(t_lem *lem)
{
	int		i;

	i = 0;
	lem->ant->len_way = (int *)ft_memalloc(sizeof(int) * lem->am->way);
	while (i < lem->am->way)
	{
		lem->ant->len_way[i] = int_len(lem->path[i]) - 1;
		i++;
	}
}

void	init_step_of_ants(t_lem *lem)
{
	init_lenght_way(lem);
	init_change_lenght_way(lem);
	init_step(lem);
	init_ant_in_step(lem);
	lem->an = lem->am->ant;
}
