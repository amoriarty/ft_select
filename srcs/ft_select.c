/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:05:11 by alegent           #+#    #+#             */
/*   Updated: 2015/05/30 11:08:23 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void					ft_update(t_lst *node)
{
	tputs(tgoto(tgetstr("cm", NULL), node->pos->x, node->pos->y), 1, ft_print);
	ft_pflag(node->entry, node->flag);
}

void						ft_select(void)
{
	t_env					*env;
	t_lst					*node;
	unsigned char				*touch;

	env = ft_sglt();
	ft_lenmax();
	node = env->arg->next;
	node->flag |= UNDER;
	ft_plst();
	while (*(touch = ft_gettouch()) != RETURN && node->next != env->arg)
	{
		if (*touch == DOWN)
		{
			node->flag |= ~(UNDER);
			node = node->next;
			node->flag |= UNDER;
			ft_update(node);
		}
		else if (*touch == ESC || *touch == DEL)
			ft_escape(&node);
	}
}
