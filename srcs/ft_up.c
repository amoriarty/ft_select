/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 14:01:45 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 14:41:06 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int									ft_up(t_lst **node)
{
	int								len;
	t_env							*env;

	env = ft_sglt();
	(*node)->flag &= ~UNDER;
	ft_update(*node);
	if ((len = ft_lstlen()) > 1)
		ft_findprev(env, node);
	else
		*node = ((*node)->prev == env->arg) ? env->arg->prev : (*node)->prev;
	(*node)->flag |= UNDER;
	if ((*node)->pos->y - env->scroll > env->screen->y)
	{
		env->scroll = len - env->screen->y;
		ft_plst();
	}
	else if ((*node)->pos->y < env->scroll && env->scroll > 0)
	{
		env->scroll--;
		ft_plst();
	}
	else
		ft_update(*node);
	return (SUCCESS);
}
