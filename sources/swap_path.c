/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:45:51 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:45:51 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	check_asceding_order(t_lem *lem)
{
	int		i;

	i = 0;
	while (i + 1 < lem->am->way)
	{
		if (int_len(lem->path[i]) <= int_len(lem->path[i + 1]))
			i++;
		else
			return (false);
	}
	return (true);
}

int		*copy(t_lem *lem, int *tmp, int i)
{
	int	len;
	int	j;

	j = 0;
	len = int_len(lem->path[i]);
	while (len > 0)
	{
		tmp[j] = lem->path[i][j];
		j++;
		len--;
	}
	len = int_len(lem->path[i]);
	j = 0;
	while (len > 0)
	{
		lem->path[i][j] = 0;
		j++;
		len--;
	}
	return (tmp);
}

void	change(t_lem *lem, int i, int k)
{
	int	j;
	int	len;

	len = int_len(lem->path[k]);
	j = 0;
	while (len > 0)
	{
		lem->path[i][j] = lem->path[k][j];
		j++;
		len--;
	}
	j = 0;
	len = int_len(lem->path[k]);
	while (len > 0)
	{
		lem->path[k][j] = 0;
		j++;
		len--;
	}
}

void	swap(t_lem *lem, int i, int k)
{
	int		*tmp;
	int		j;
	int		len;

	tmp = (int *)ft_memalloc(sizeof(int) * lem->am->room + 1);
	tmp = copy(lem, tmp, i);
	change(lem, i, k);
	len = int_len(tmp);
	j = 0;
	while (len > 0)
	{
		lem->path[k][j] = tmp[j];
		j++;
		len--;
	}
	free(tmp);
}

void	swap_path_in_asceting_order(t_lem *lem)
{
	int		i;

	while (!(check_asceding_order(lem)))
	{
		i = 0;
		while (i + 1 < lem->am->way)
		{
			if (int_len(lem->path[i]) > int_len(lem->path[i + 1]))
				swap(lem, i, i + 1);
			i++;
		}
	}
}
