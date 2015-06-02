/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 14:01:45 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 14:05:42 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int									ft_up(t_lst **node)
{
	t_env							*env;

	env = ft_sglt();
	(*node)->flag &= ~UNDER;
	ft_update(*node);
	if (ft_lstlen() > 1)
		ft_findprev(env, node);
	else
		*node = ((*node)->prev == env->arg) ? env->arg->prev : (*node)->prev;
	(*node)->flag |= UNDER;
	if ((*node)->pos->y - env->scroll >= env->screen->y)
	{
		env->scroll = (*node)->pos->y - env->screen->y;
		env->scroll++;
		ft_plst();
	}
	else if ((*node)->pos->y < env->screen->y + env->scroll
			&& env->scroll > 0)
	{
		env->scroll--;
		ft_plst();
	}
	else
		ft_update(*node);
	return (SUCCESS);
}
