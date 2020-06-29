/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_for_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:43:22 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:43:22 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		do_for_positive(t_all *st, char *s, int len)
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
	if (st->flag[1] != 'e')
	{
		ft_fwrite(0, &st->flag[1], 1);
		st->count++;
	}
	ft_fwrite(0, s, len);
}

void		do_for_negative(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		ft_fwrite(0, "-", 1);
		ft_fwrite(0, s, len);
		st->count += 2;
		while (--st->len - len > 0)
		{
			ft_fwrite(0, " ", 1);
			st->count++;
		}
	}
	else if (st->flag[0] == '0' && st->acc == -1)
		put_number_with_minus(st, len, s);
	else
	{
		while (st->len-- - len > 1)
		{
			ft_fwrite(0, " ", 1);
			st->count++;
		}
		ft_fwrite(0, "-", 1);
		ft_fwrite(0, s, len);
		st->count += len + 1;
	}
}

void		int_with_flags(t_all *st, char *s, int len)
{
	if (st->flag[0] == '-')
	{
		if (st->flag[1] != 'e')
		{
			ft_fwrite(0, &st->flag[1], 1);
			st->count++;
			st->len--;
		}
		ft_fwrite(0, s, len);
		st->count += len;
		while (st->len-- - len > 0)
		{
			ft_fwrite(0, " ", 1);
			st->count++;
		}
	}
	else if (st->flag[0] == '0' && st->acc == -1)
		put_number_with_flag(st, len, s);
	else
		do_for_positive(st, s, len);
}

void		do_for_int(t_all *st)
{
	int			buf;
	char		*s;
	int			len;

	buf = (int)va_arg(st->args, int);
	if (buf == 0 && st->acc != -1)
		null_with_acc(st);
	else
	{
		st->sign = (buf < 0) ? 1 : 0;
		s = ft_l_itoa(ft_labs(buf));
		len = ft_strlen(s);
		if (st->acc > len)
			foo(&s, st, &len);
		if (st->sign == 1)
			do_for_negative(st, s, len);
		else
			int_with_flags(st, s, len);
		free(s);
	}
}
