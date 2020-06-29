/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_u_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:42:03 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:42:03 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	do_for_u_no_flags(t_all *st, char *s, int len)
{
	if (st->len != 0 && st->len > len && st->flag[1] == 'e')
		while (st->len-- - len > 0)
		{
			ft_fwrite(0, " ", 1);
			st->count++;
		}
	else if (st->len != 0 && st->len > len && st->flag[1] != 'e')
		while (st->len-- - len > 1)
		{
			ft_fwrite(0, " ", 1);
			st->count++;
		}
	ft_fwrite(0, s, len);
}

void	u_int_with_flags(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		ft_fwrite(0, s, len);
		while (st->len-- - len > 0)
			ft_fwrite(0, " ", 1);
	}
	else if (st->flag[0] == '0' && st->acc == -1)
	{
		while (st->len-- - len > 0)
			ft_fwrite(0, "0", 1);
		ft_fwrite(0, s, len);
	}
	else
		do_for_u_no_flags(st, s, len);
}

void	do_for_u_int(t_all *st)
{
	unsigned int	buf;
	char			*s;
	int				len;

	buf = (unsigned int)va_arg(st->args, unsigned long int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		s = ft_l_itoa(buf);
		len = ft_strlen(s);
		if (st->acc > len)
			foo(&s, st, &len);
		u_int_with_flags(st, s, len);
		free(s);
	}
}
