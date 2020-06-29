/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 01:35:01 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/26 01:35:01 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*find_room_name(t_lem *lem, int index, t_room *room)
{
	char *str;

	if (index == 0)
	{
		str = ft_strdup(lem->se->start);
		return (str);
	}
	if (index == lem->am->room - 1)
	{
		str = ft_strdup(lem->se->end);
		return (str);
	}
	while (index != room->index)
	{
		room = room->next;
	}
	if (index == room->index)
	{
		str = ft_strdup(room->name);
		return (str);
	}
	return (NULL);
}

int		len_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	count_ways(t_lem *lem, t_ver *ver)
{
	lem->am->way = 0;
	while (ver->next != NULL)
	{
		lem->am->way++;
		ver = ver->next;
	}
}
