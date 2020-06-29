/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <Student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:52:08 by Student           #+#    #+#             */
/*   Updated: 2020/05/31 19:53:00 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_mat(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->am->room)
	{
		free(lem->mat[i]);
		i++;
	}
	free(lem->mat);
}

void	free_new_path(int **new_path, int way)
{
	int		i;

	i = 0;
	while (i < way)
	{
		free(new_path[i]);
		i++;
	}
	free(new_path);
}

void	free_ant(t_lem *lem)
{
	int		i;
	int		len;

	i = 0;
	len = 10000;
	if (lem->am->ant > 10000)
		len = lem->am->ant;
	while (i < len)
	{
		free(lem->ant->step[i]);
		i++;
	}
	i = 0;
	while (i < len)
	{
		free(lem->ant->ant[i]);
		i++;
	}
	free(lem->ant->ant);
	free(lem->ant->step);
	free(lem->ant->c_len_way);
	free(lem->ant->len_way);
	free(lem->ant);
	lem->ant = NULL;
}

void	free_tmp_ver(t_ver *ver, t_ver *lem_ver)
{
	t_ver *tmp;
	t_ver *next;

	tmp = ver;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp->ver);
		free(tmp);
		tmp = next;
	}
	lem_ver = NULL;
	ver = NULL;
}

void	free_all(t_lem *lem, t_ver *ver)
{
	free_tmp_ver(ver, lem->ver);
	free_mat(lem);
	free_room(lem);
	free_link(lem);
	free_se(lem);
	free_ant(lem);
	free_remember(lem);
	free_lem_in(lem);
}
