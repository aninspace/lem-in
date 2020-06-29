/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_name_with_dashes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:00:55 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/26 19:34:07 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_start_end(t_lem *lem, char *str)
{
	if (lem->start == NULL || lem->end == NULL)
	{
		lem->found = ft_strstr(str, lem->se->start);
		if (lem->found)
		{
			if (lem->found - str == 0)
				lem->start = ft_strdup(lem->se->start);
			if (lem->found - str > 0)
				lem->end = ft_strdup(lem->se->start);
		}
		lem->found = ft_strstr(str, lem->se->end);
		if (lem->found)
		{
			if (lem->found - str == 0)
				lem->start = ft_strdup(lem->se->end);
			if (lem->found - str > 0)
				lem->end = ft_strdup(lem->se->end);
		}
	}
}

int		how_many_dashes(char *str)
{
	int		i;
	int		dash;

	i = 0;
	dash = 0;
	while (str[i])
	{
		if (str[i] == '-')
			dash++;
		i++;
	}
	return (dash);
}

char	*link_name_with_dashes(t_lem *lem, t_room *room, char *str)
{
	t_room	*tmp;
	char	*joinstr;

	tmp = room;
	while (tmp->next != NULL)
	{
		lem->found = ft_strstr(str, tmp->name);
		if (lem->found)
		{
			if (lem->found - str == 0)
				lem->start = ft_strdup(tmp->name);
			if (lem->found - str > 0)
				lem->end = ft_strdup(tmp->name);
		}
		tmp = tmp->next;
	}
	lem->found = NULL;
	check_start_end(lem, str);
	if (lem->start != NULL && lem->end != NULL)
	{
		joinstr = ft_strjoin(lem->start, " ");
		joinstr = ft_strjoin(joinstr, lem->end);
		return (joinstr);
	}
	return (NULL);
}
