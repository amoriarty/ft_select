/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:05:11 by alegent           #+#    #+#             */
/*   Updated: 2015/05/30 11:42:29 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
		if (tgetstr("kr", NULL))
		{
			node->flag |= ~(UNDER);
			ft_update(node);
			node = node->next;
			node->flag |= UNDER;
			ft_update(node);
		}
		else if (*touch == ESC || *touch == DEL)
		{
			ft_putnbr((*touch) + 1);
			ft_escape(&node);
		}
	}
	ft_putstr((char *)touch);
}
