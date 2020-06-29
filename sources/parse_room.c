/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 01:23:07 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/29 00:13:34 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		init_start_room(t_lem *lem, char **split)
{
	lem->se->start = ft_strdup(split[0]);
	lem->se->start_c_x = ft_atoi(split[1]);
	lem->se->start_c_y = ft_atoi(split[2]);
	lem->se->index_s = 0;
}

void		init_end_room(t_lem *lem, char **split)
{
	lem->se->end = ft_strdup(split[0]);
	lem->se->end_c_x = ft_atoi(split[1]);
	lem->se->end_c_y = ft_atoi(split[2]);
}

void		init_all_room(t_lem *lem, char **split)
{
	lem->room->name = ft_strdup(split[0]);
	lem->room->c_x = ft_atoi(split[1]);
	lem->room->c_y = ft_atoi(split[2]);
	lem->room->next = (t_room *)ft_memalloc(sizeof(t_room));
	lem->room->index = lem->r;
	lem->room = lem->room->next;
	lem->r++;
}

bool		is_room(t_lem *lem, char *line)
{
	char	**split;
	char	*str;

	str = ft_strtrim(line);
	split = ft_strsplit(str, ' ');
	if (len_arr(split) != 3 || !(ft_is_number(split[1])) ||
		!(ft_is_number(split[2])) || split[0][0] == 'L' || split[0][0] == '#')
	{
		ft_free_arr(split);
		free(str);
		str = NULL;
		return (false);
	}
	if (lem->am->s == 1 && lem->se->start == NULL)
		init_start_room(lem, split);
	else if (lem->am->e == 1 && lem->se->end == NULL)
		init_end_room(lem, split);
	else
		init_all_room(lem, split);
	free(str);
	str = NULL;
	ft_free_arr(split);
	return (true);
}
