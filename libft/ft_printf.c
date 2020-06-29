/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:38:39 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:38:39 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *fmt, ...)
{
	t_all		*st;
	int			len;

	if (!(st = (t_all*)malloc(sizeof(t_all))))
		return (-1);
	st->fmt = (char *)fmt;
	st->fmt_cp = st->fmt;
	st->i = 0;
	len = ft_strlen(st->fmt);
	st = init_st(st);
	if (fmt)
	{
		va_start(st->args, fmt);
		st->len = parse(st);
		va_end(st->args);
	}
	len = st->len;
	free(st);
	return (len);
}
