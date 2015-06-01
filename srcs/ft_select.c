/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:05:11 by alegent           #+#    #+#             */
/*   Updated: 2015/06/01 14:29:17 by alegent          ###   ########.fr       */
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
	while (*(touch = ft_gettouch()) != RETURN)
	{
		if (ft_over() <= 1)
		{
			ft_unsetenv();
			exit(EXIT_SUCCESS);
		}
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
			else if (touch[0] == DEL || touch[BUF - 2] == '~')
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
