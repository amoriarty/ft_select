/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 11:16:03 by alegent           #+#    #+#             */
/*   Updated: 2015/06/01 11:23:41 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					ft_direction(t_lst **node, char *touch)
{
	t_env				*env;

	env = ft_sglt();
	if (touch[0] == ESC)
	{
		if (touch[2] == DOWN || touch[2] == RIGHT)
		{
			(*node)->flag &= ~UNDER;
			ft_update(*node);
			*node = ((*node)->next == env->arg) ? env->arg->next : (*node)->next;
			(*node)->flag |= UNDER;
			ft_update(*node);
			return (SUCCESS);
		}
		if (touch[2] == UP || touch[2] == LEFT)
		{
			(*node)->flag &= ~UNDER;
			ft_update(*node);
			*node = ((*node)->prev == env->arg) ? env->arg->prev : (*node)->prev;
			(*node)->flag |= UNDER;
			ft_update(*node);
			return (SUCCESS);
		}
	}
	return (FAILURE);
}
