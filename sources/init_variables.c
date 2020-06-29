/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:47:30 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:47:30 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			init_mat(t_lem *lem)
{
	int			i;

	i = 0;
	lem->mat = (int **)ft_memalloc(sizeof(int *) * lem->am->room + 1);
	while (i < lem->am->room)
	{
		lem->mat[i] = (int *)ft_memalloc(sizeof(int) * lem->am->room + 1);
		i++;
	}
}

void			init_path(t_lem *lem, int way)
{
	int			i;

	i = 0;
	if (lem->path)
	{
		while (i < lem->am->way)
		{
			free(lem->path[i]);
			i++;
		}
		free(lem->path);
	}
	i = 0;
	lem->path = (int **)ft_memalloc(sizeof(int *) * (way + 1));
	while (i < way)
	{
		lem->path[i] = (int *)ft_memalloc(sizeof(int) * (lem->am->room + 1));
		i++;
	}
}

int				**init_new_path(t_lem *lem, int way)
{
	int			**new_path;
	int			j;

	new_path = (int **)ft_memalloc(sizeof(int *) * way + 1);
	j = 0;
	while (j < way)
	{
		new_path[j] = (int *)ft_memalloc(sizeof(int) * lem->am->room + 1);
		j++;
	}
	return (new_path);
}

void			init_step(t_lem *lem)
{
	int			i;
	int			len;

	i = 0;
	len = 10000;
	if (lem->am->ant > 10000)
		len = lem->am->ant;
	lem->ant->step = (int **)ft_memalloc(sizeof(int *) * len);
	if (lem->am->room > 20)
	{
		while (i < len)
		{
			lem->ant->step[i] = (int *)ft_memalloc(sizeof(int) * lem->am->room);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			lem->ant->step[i] = (int *)ft_memalloc(sizeof(int)
												* lem->am->room * 2);
			i++;
		}
	}
}

void			init_ant_in_step(t_lem *lem)
{
	int			i;
	int			len;

	i = 0;
	len = 10000;
	if (lem->am->ant > 10000)
		len = lem->am->ant;
	lem->ant->ant = (int **)ft_memalloc(sizeof(int *) * len);
	if (lem->am->room > 20)
	{
		while (i < len)
		{
			lem->ant->ant[i] = (int *)ft_memalloc(sizeof(int) * lem->am->room);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			lem->ant->ant[i] = (int *)ft_memalloc(sizeof(int) *
														lem->am->room * 2);
			i++;
		}
	}
}
