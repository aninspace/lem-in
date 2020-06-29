/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:46:25 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:46:25 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool		amount_ants(t_lem *lem, char *line)
{
	if (ft_atoi(line) == 0 || ft_atoi(line) < 0 ||
	!(ft_is_number(line)) || ft_atoi(line) >= 2147483647)
	{
		ft_putstr("ERROR: ");
		ft_putstr("bad ants\n");
		exit(0);
	}
	lem->am->ant = ft_atoi(line);
	return (true);
}

bool		is_comment(char *line)
{
	char	*str;
	char	**split;

	str = ft_strtrim(line);
	split = ft_strsplit(str, ' ');
	if (str[0] != '#' || str[2] == '#' ||
		(ft_strcmp(line, "##start") == 0) ||
		(ft_strcmp(line, "##end") == 0))
	{
		free(str);
		ft_free_arr(split);
		return (false);
	}
	if (len_arr(split) == 3)
	{
		if (ft_is_number(split[1]) || ft_is_number(split[2]))
			return (false);
	}
	free(str);
	ft_free_arr(split);
	return (true);
}

bool		is_start(char *line)
{
	char	*str;

	str = ft_strtrim(line);
	if (!(ft_strcmp(str, "##start") == 0))
	{
		free(str);
		return (false);
	}
	free(str);
	str = NULL;
	return (true);
}

bool		is_end(char *line)
{
	char	*str;

	str = ft_strtrim(line);
	if (!(ft_strcmp(str, "##end") == 0))
	{
		free(str);
		return (false);
	}
	free(str);
	str = NULL;
	return (true);
}

bool		is_command(char *line)
{
	char	*str;

	str = ft_strtrim(line);
	if (str[0] != '#' || str[1] != '#' ||
	ft_strcmp("##start", line) == 0 || ft_strcmp("##end", line) == 0)
	{
		free(str);
		return (false);
	}
	free(str);
	str = NULL;
	return (true);
}
