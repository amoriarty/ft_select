/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:49:31 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 18:32:02 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_plst(void)
{
	int						y;
	t_env					*env;
	t_lst					*tmp;

	y = 0;
	env = ft_sglt();
	tmp = env->arg->next;
	ft_poscal();
	ft_putstr_fd(tgetstr("cl", NULL), ft_tty());
	while (tmp != env->arg)
	{
		y = tmp->pos->y - env->scroll;
		if (y > -1 && y < env->screen->y)
		{
			tputs(tgoto(tgetstr("cm", NULL), tmp->pos->x, y),
					1, ft_print);
			ft_pflag(tmp->entry, tmp->flag);
		}
		tmp = tmp->next;
	}
}
