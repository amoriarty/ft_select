/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:05:11 by alegent           #+#    #+#             */
/*   Updated: 2015/06/01 13:43:54 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_select(void)
{
	t_env					*env;
	t_lst					*node;
	char					*touch;

	env = ft_sglt();
	ft_lenmax();
	node = env->arg->next;
	node->flag |= UNDER;
	ft_plst();
	while (*(touch = ft_gettouch()) != RETURN && ft_over() > 1)
	{
		if (ft_direction(&node, touch) == FAILURE)
		{
			if (touch[0] == SPACE)
			{
				if (node->flag & REVERSE)
					node->flag &= ~REVERSE;
				else
					node->flag |= REVERSE;
				ft_update(node);
			}
			else if (touch[0] == DEL && (tgetstr("kb", NULL) || tgetstr("dc", NULL)))
				ft_del(&node);
			else if (touch[0] == ESC)
			{
				ft_unsetenv();
				exit(EXIT_SUCCESS);
			}
		}
		free(touch);
	}
}
