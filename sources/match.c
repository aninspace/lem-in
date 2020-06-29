/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:47:02 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:47:02 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	match_se(t_lem *lem, t_link *link)
{
	t_link	*tmp_link;

	tmp_link = link;
	while (link->next != NULL &&
		ft_strcmp(lem->se->start, link->start) != 0 &&
		ft_strcmp(lem->se->start, link->end))
		link = link->next;
	if (link->next == NULL)
		return (false);
	link = tmp_link;
	while (link->next != NULL &&
		ft_strcmp(lem->se->end, link->start) != 0 &&
		ft_strcmp(lem->se->end, link->end))
		link = link->next;
	if (link->next == NULL)
		return (false);
	return (true);
}
