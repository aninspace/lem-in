/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crossroads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdonnor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:44:23 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 19:44:23 by rdonnor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	crossroad_for_int(t_all *st)
{
	if (st->size == '\0')
		do_for_int(st);
	else if (st->size == 'l' || st->fmt_cp[st->i] == 'D')
		do_for_l_int(st);
	else if (st->size == 'L')
		do_for_ll_int(st);
	else if (st->size == 'h')
		do_for_h_int(st);
	else if (st->size == 'H')
		do_for_hh_int(st);
}

void	crossroad_for_u(t_all *st)
{
	if (st->size == '\0')
		do_for_u_int(st);
	else if (st->size == 'l' || st->fmt_cp[st->i] == 'U')
		do_for_l_uns(st);
	else if (st->size == 'L')
		do_for_ll_uns(st);
	else if (st->size == 'h')
		do_for_h_uns(st);
	else if (st->size == 'H')
		do_for_hh_uns(st);
}

void	crossroad_for_oct(t_all *st)
{
	if (st->size == '\0')
		do_for_oct(st);
	else if (st->size == 'l' || st->fmt_cp[st->i] == 'U')
		do_for_l_oct(st);
	else if (st->size == 'L')
		do_for_ll_oct(st);
	else if (st->size == 'h')
		do_for_h_oct(st);
	else if (st->size == 'H')
		do_for_hh_oct(st);
}

void	crossroad_for_hex(t_all *st)
{
	if (st->size == '\0')
		do_for_hex(st);
	else if (st->size == 'l')
		do_for_l_hex(st);
	else if (st->size == 'L')
		do_for_ll_hex(st);
	else if (st->size == 'h')
		do_for_h_hex(st);
	else if (st->size == 'H')
		do_for_hh_hex(st);
}

void	crossroad_for_floats(t_all *st)
{
	if (st->size == '\0')
		do_for_floats(st);
	else if (st->size == 'L' || st->fmt_cp[st->i] == 'F')
		do_for_l_floats(st);
}
