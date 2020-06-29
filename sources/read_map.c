/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:45:40 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:45:40 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool		validate(t_lem *lem, t_link *link, t_room *room)
{
	if (lem->am->room < 2 || lem->am->link == 0 || lem->am->s != 1 ||
	lem->am->ant <= 0 || lem->am->e != 1 || !(match_se(lem, link)) ||
	!(check_link_duplicate(link)) || !(check_link_reserve_duplicate(link)) ||
	!(check_dupl_coord(lem, room)) || !(check_name_duplicate(lem, room)))
	{
		if (lem->am->s != 1)
			ft_putstr("ERROR: no or too many start room\n");
		else if (lem->am->e != 1)
			ft_putstr("ERROR: no or too many end room\n");
		else if (lem->am->link == 0)
			ft_putstr("ERROR: no link\n");
		else
			ft_putstr("ERROR: most likely it is duplicate\n");
		return (false);
	}
	return (true);
}

void		parse_map(t_lem *lem, char *line, t_room *tmp_room)
{
	if (is_command(line) && !((lem->am->e == 1 && lem->se->end
		== NULL) || (lem->am->s == 1 && lem->se->start == NULL)))
		lem->am->cmd++;
	else if (lem->am->ant == 0)
		amount_ants(lem, line);
	else if (is_room(lem, line) && lem->am->link == 0)
		lem->am->room++;
	else if (lem->se->start != NULL &&
			lem->se->end != NULL &&
			is_link(lem, line, tmp_room))
		lem->am->link++;
	else if (is_comment(line) &&
			!((lem->am->e == 1 && lem->se->end == NULL) ||
			(lem->am->s == 1 && lem->se->start == NULL)))
		lem->am->comment++;
	else if (is_end(line))
		lem->am->e++;
	else if (is_start(line))
		lem->am->s++;
	else
	{
		ft_putstr("ERROR: smth is loosed\n");
		free(line);
		exit(EXIT_FAILURE);
	}
}

bool		read_map(t_lem *lem)
{
	char	*line;
	t_link	*tmp_link;
	t_room	*tmp_room;
	int		i;

	lem->remember = (char **)ft_memalloc(sizeof(char *) * 100000);
	tmp_link = lem->link;
	tmp_room = lem->room;
	i = 0;
	while (get_next_line(lem->fd, &line) > 0)
	{
		parse_map(lem, line, tmp_room);
		lem->remember[i] = ft_strdup(line);
		lem->height++;
		free(line);
		i++;
	}
	lem->link->next = NULL;
	lem->link = tmp_link;
	lem->room = tmp_room;
	lem->se->index_e = lem->am->room - 1;
	if (!(validate(lem, tmp_link, tmp_room)))
		return (false);
	return (true);
}
