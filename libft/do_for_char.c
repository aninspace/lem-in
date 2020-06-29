/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:44:35 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:44:35 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	do_for_percent(t_all *st)
{
	char	c;

	c = '%';
	if (st->flag[0] == '-')
	{
		ft_fwrite(0, &c, 1);
		while (st->len-- > 1)
			ft_fwrite(0, " ", 1);
	}
	else if (st->flag[0] == '0')
	{
		while (st->len-- > 1)
			ft_fwrite(0, "0", 1);
		ft_fwrite(0, &c, 1);
		st->len--;
	}
	else
	{
		while (st->len-- > 1)
			ft_fwrite(0, " ", 1);
		ft_fwrite(0, &c, 1);
		st->len--;
	}
}

void	do_for_char(t_all *st)
{
	char	c;

	c = (char)va_arg(st->args, unsigned int);
	if (st->flag[0] == '-')
	{
		ft_fwrite_c(0, &c, 1);
		while (st->len-- > 1)
			ft_fwrite(0, " ", 1);
	}
	else if (st->flag[0] == '0')
	{
		while (st->len-- > 1)
			ft_fwrite(0, "0", 1);
		ft_fwrite_c(0, &c, 1);
		st->len--;
	}
	else
	{
		while (st->len-- > 1)
			ft_fwrite(0, " ", 1);
		ft_fwrite_c(0, &c, 1);
		st->len--;
	}
}
