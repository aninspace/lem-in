/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:50:35 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:50:35 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			int_len(int *k)
{
	int		am;

	am = 0;
	while (k[am])
		am++;
	return (am);
}

int			*int_copy(int *dest, int *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void		print_map(t_lem *lem)
{
	int		i;

	i = 0;
	while (lem->remember[i])
	{
		ft_printf("%s\n", lem->remember[i]);
		i++;
	}
	ft_printf("\n");
}
