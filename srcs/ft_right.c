/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 13:54:27 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 13:57:05 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int									ft_right(t_lst **node)
{
	t_env							*env;

	env = ft_sglt();
	(*node)->flag &= ~UNDER;
	ft_update(*node);
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
