/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:50:53 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:51:53 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ver		*algo(t_lem *lem)
{
	t_ver	*tmp_ver;
	int		k;

	k = 0;
	while (true)
	{
		algo_deixtra(lem);
		if (lem->d[lem->se->index_e] != INT_MAX)
			recovery_way(lem, lem->d);
		else
			break ;
		if (k == 0)
			tmp_ver = lem->ver;
		change_graph_weight(lem);
		lem->ver->next = (t_ver *)ft_memalloc(sizeof(t_ver));
		lem->ver = lem->ver->next;
		k++;
	}
	if (k == 0)
	{
		ft_putstr("ERROR: ");
		ft_putstr("no way\n");
		exit(EXIT_FAILURE);
	}
	return (tmp_ver);
}

void		ways(t_lem *lem, t_ver *tmp_ver)
{
	null_graph(lem);
	connect_ways(lem, tmp_ver);
	count_ways(lem, tmp_ver);
	init_path(lem, lem->am->way);
}

void		path(t_lem *lem)
{
	check_valid(lem);
	check_paths(lem, lem->pt);
	swap_path_in_asceting_order(lem);
}

void		argument(t_lem *lem, int argc, char **argv, int fl)
{
	if (fl == 0)
	{
		if (argv[1] && argc != 2)
		{
			ft_putstr("ERROR\n");
			exit(EXIT_FAILURE);
		}
		if (argv[1] && argc == 2)
			lem->fd = open(argv[1], O_RDONLY);
	}
	if (fl == 1)
	{
		if (argc > 2)
		{
			ft_putstr("ERROR\n");
			exit(EXIT_FAILURE);
		}
	}
}

int			main(int argc, char **argv)
{
	t_lem	*lem;
	t_ver	*tmp_ver;

	lem = full_init();
	argument(lem, argc, argv, 0);
	if (!(read_map(lem)))
		exit(EXIT_FAILURE);
	if (lem->fd == 0)
		argument(lem, argc, argv, 1);
	lem->ant = init_ant(lem);
	tmp_ver = algo(lem);
	ways(lem, tmp_ver);
	while (lem->p < lem->am->way)
	{
		find_way(lem, lem->am->room);
		null_one_way(lem);
		lem->p++;
	}
	init_struct_path(lem);
	path(lem);
	print_map(lem);
	step_of_ants(lem);
	free_all(lem, tmp_ver);
	return (0);
}
