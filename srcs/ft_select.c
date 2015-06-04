/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:05:11 by alegent           #+#    #+#             */
/*   Updated: 2015/06/04 20:40:15 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void					ft_end(int n)
{
	ft_unsetenv();
	exit(n);
}

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
			ft_end(EXIT_SUCCESS);
		if (ft_direction(&node, touch) == FAILURE)
		{
			if (touch[0] == SPACE)
				ft_space(env, &node);
			else if (touch[0] == DEL || touch[BUF - 2] == '~')
				ft_del(&node);
			else if (touch[0] == ESC)
				ft_end(EXIT_SUCCESS);
		}
		free(touch);
	}
	ft_sentres();
}
