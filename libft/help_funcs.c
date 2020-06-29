/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <Student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:40:01 by Student           #+#    #+#             */
/*   Updated: 2020/05/31 19:40:01 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_null(t_all *st)
{
	int i;

	i = 0;
	if (st->flag[1] != 'e')
	{
		ft_fwrite(0, &st->flag[1], 1);
		st->len--;
	}
	while (st->acc - i++ > 0)
		ft_fwrite(0, "0", 1);
	while (st->len-- - st->acc > 0)
		ft_fwrite(0, " ", 1);
}

void	put_number_with_flag(t_all *st, int len, char *s)
{
	if (st->flag[1] != 'e')
	{
		ft_fwrite(0, &st->flag[1], 1);
		st->len--;
		st->count++;
	}
	while (st->len-- - len > 0)
	{
		ft_fwrite(0, "0", 1);
		st->count++;
	}
	ft_fwrite(0, s, len);
	st->count += len;
}

void	put_number_with_minus(t_all *st, int len, char *s)
{
	ft_fwrite(0, "-", 1);
	while (--st->len - len > 0)
	{
		ft_fwrite(0, "0", 1);
		st->count++;
	}
	ft_fwrite(0, s, len);
	st->count += len + 1;
}

void	foo(char **s, t_all *st, int *len)
{
	char	*temp;
	char	*s_buf;

	s_buf = (char *)malloc(sizeof(char) * (st->acc - *len + 1));
	s_buf[st->acc - *len - 1] = '\0';
	s_buf = ft_memset(s_buf, '0', st->acc - *len);
	temp = *s;
	*s = ft_strjoin(s_buf, temp);
	*len = ft_strlen(*s);
	free(s_buf);
	free(temp);
}

void	null_with_no_acc_hex(t_all *st)
{
	int i;

	i = 0;
	if (st->len == 0)
		ft_fwrite(0, "0", 1);
	else
	{
		if (st->flag[0] == '-')
		{
			ft_fwrite(0, "0", 1);
			while (--st->len > 0)
				ft_fwrite(0, " ", 1);
		}
		else if (st->flag[0] == '0')
		{
			while (st->len-- > 0)
				ft_fwrite(0, "0", 1);
		}
		else
		{
			while (--st->len > 0)
				ft_fwrite(0, " ", 1);
			ft_fwrite(0, "0", 1);
		}
	}
}
