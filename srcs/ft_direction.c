/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 11:16:03 by alegent           #+#    #+#             */
/*   Updated: 2015/06/01 13:20:22 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int				ft_left(t_lst **node)
{
	t_env				*env;

	env = ft_sglt();
	(*node)->flag &= ~UNDER;
	ft_update(*node);
	*node = ((*node)->prev == env->arg) ? env->arg->prev : (*node)->prev;
	(*node)->flag |= UNDER;
	ft_update(*node);
	return (SUCCESS);
}

static int				ft_up(t_lst **node)
{
	int				start;
	t_env				*env;

	env = ft_sglt();
	(*node)->flag &= ~UNDER;
	ft_update(*node);

	if (ft_lstlen())
	{
		start = (*node)->pos->y;
		while ((*node)->pos->y == start)
			*node = ((*node)->prev == env->arg) ? env->arg->prev : (*node)->prev;
	}
	else
		*node = ((*node)->prev == env->arg) ? env->arg->prev : (*node)->prev;
	(*node)->flag |= UNDER;
	ft_update(*node);
	return (SUCCESS);
}

static int				ft_right(t_lst **node)
{
	t_env				*env;

	env = ft_sglt();
	(*node)->flag &= ~UNDER;
	ft_update(*node);
	*node = ((*node)->next == env->arg) ? env->arg->next : (*node)->next;
	(*node)->flag |= UNDER;
	ft_update(*node);
	return (SUCCESS);
}

static int				ft_down(t_lst **node)
{
	t_pos				start;
	t_env				*env;

	env = ft_sglt();
	(*node)->flag &= ~UNDER;
	ft_update(*node);
	if (ft_lstlen() > 1)
	{
		start.y = (*node)->pos->y;
		while ((*node)->pos->y == start.y)
			*node = ((*node)->next == env->arg) ? env->arg->next : (*node)->next;
	}
	else
		*node = ((*node)->next == env->arg) ? env->arg->next : (*node)->next;
	(*node)->flag |= UNDER;
	ft_update(*node);
	return (SUCCESS);
}

int					ft_direction(t_lst **node, char *touch)
{
	if (touch[0] == ESC)
	{
		if (touch[2] == DOWN)
			return (ft_down(node));
		else if (touch[2] == RIGHT)
			return (ft_right(node));
		else if (touch[2] == UP)
			return (ft_up(node));
		else if (touch[2] == LEFT)
			return (ft_left(node));
	}
	return (FAILURE);
}
