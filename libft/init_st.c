/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:40:33 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:40:33 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reinit_st(t_all *st)
{
	st->flag[0] = 'e';
	st->flag[1] = 'e';
	st->flag[2] = 'e';
	st->size = '\0';
	st->len = 0;
	st->acc = -1;
	st->sign = 0;
}

t_all	*init_st(t_all *st)
{
	st->flag[0] = 'e';
	st->flag[1] = 'e';
	st->flag[2] = 'e';
	st->size = '\0';
	st->len = 0;
	st->acc = -1;
	st->fmt_cp = st->fmt;
	st->count = 0;
	st->sign = 0;
	return (st);
}
