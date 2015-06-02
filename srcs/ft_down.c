/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 13:49:59 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 13:54:11 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int									ft_down(t_lst **node)
{
	int								len;
	t_env							*env;

	env = ft_sglt();
	len = ft_lstlen();
	(*node)->flag &= ~UNDER;
	ft_update(*node);
	if (len > 1)
		ft_findnext(env, node, len);
	else
		*node = ((*node)->next == env->arg) ? env->arg->next : (*node)->next;
	(*node)->flag |= UNDER;
	if ((*node)->pos->y - env->scroll >= env->screen->y)
	{
		env->scroll++;
		ft_plst();
	}
	else if ((*node)->pos->y == 0)
	{
		env->scroll = 0;
		ft_plst();
	}
	else
		ft_update(*node);
	return (SUCCESS);
}
