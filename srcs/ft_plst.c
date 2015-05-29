/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:49:31 by alegent           #+#    #+#             */
/*   Updated: 2015/05/29 16:40:31 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_ptype(char *entry, int flag)
{
	if (flag & REVERSE)
		ft_putstr(tgetstr("mr", NULL));
	if (flag & UNDER)
		ft_putstr(tgetstr("us", NULL));
	ft_putstr(entry);
	if (flag & (UNDER | REVERSE))
		ft_putstr(tgetstr("me", NULL));
}

void						ft_plst(void)
{
	t_env					*env;
	t_lst					*tmp;

	env = ft_sglt();
	tmp = env->arg->next;
	ft_poscal();
	ft_putstr(tgetstr("cl", NULL));
	while (tmp != env->arg)
	{
		tputs(tgoto(tgetstr("cm", NULL), tmp->pos->x, tmp->pos->y),
				1, ft_print);
		ft_ptype(tmp->entry, tmp->flag);
		tmp = tmp->next;
	}
}
