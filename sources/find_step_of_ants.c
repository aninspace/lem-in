/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_step_of_ants.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:48:01 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 21:09:35 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		fill_previous_step(t_lem *lem, int j, int i, int k)
{
	t_room	*tmp_room;
	char	*str;

	tmp_room = lem->room;
	lem->ant->step[lem->t][k] = lem->path[j][i];
	while (!(is_ant_in_step(lem, lem->t - 1, lem->a)))
		lem->a++;
	lem->ant->ant[lem->t][k] = lem->a;
	ft_printf("L%d-", lem->a);
	str = find_room_name(lem, lem->path[j][i], tmp_room);
	ft_printf("%s ", str);
	k++;
	lem->a++;
	free(str);
	return (k);
}

int		put_ant_in_previous_step(t_lem *lem, int i)
{
	int		k;
	int		j;
	int		amount;

	k = 0;
	j = 0;
	lem->a = 1;
	amount = count_previous_step(lem, i);
	while (lem->a < lem->am->ant + 1 && k < amount)
	{
		j = 0;
		while (j < lem->am->way && (check_lenght_path(lem, i) > 0)
		&& k < amount && lem->a < lem->am->ant + 1)
		{
			if (lem->path[j][i] && check_ant_in_previous_step(lem, lem->t, j, i)
			&& k < amount)
				k = fill_previous_step(lem, j, i, k);
			j++;
		}
		i--;
	}
	return (k);
}

void	finish_map(t_lem *lem)
{
	int		k;

	k = 1;
	while (k != 0)
	{
		lem->t++;
		k = put_ant_in_previous_step(lem, lem->t);
		if (k != 0)
			ft_printf("\n");
	}
}

int		fill_current_step(t_lem *lem, int k, int i, int p)
{
	t_room	*tmp_room;
	char	*str;

	tmp_room = lem->room;
	lem->ant->step[lem->t][k] = lem->path[i][p];
	lem->ant->ant[lem->t][k] = lem->r_ant;
	str = find_room_name(lem, lem->path[i][p], tmp_room);
	ft_printf("L%d-%s ", lem->r_ant, str);
	k++;
	lem->r_ant++;
	lem->an--;
	free(str);
	return (k);
}

void	step_of_ants(t_lem *lem)
{
	int		i;
	int		k;
	int		p;

	init_step_of_ants(lem);
	k = 0;
	while (lem->an > 0)
	{
		if (lem->an != lem->am->ant)
		{
			lem->t++;
			k = put_ant_in_previous_step(lem, lem->t);
		}
		i = 0;
		p = 0;
		while (i < lem->am->way)
		{
			if (lem->an > lem->ant->c_len_way[i])
				k = fill_current_step(lem, k, i, p);
			i++;
		}
		ft_printf("\n");
	}
	finish_map(lem);
}
