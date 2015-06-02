/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 18:03:08 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 11:28:59 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void							ft_findnext(t_env *env, t_lst **node, int len)
{
	int							todo;
	t_pos						start;

	todo = TRUE;
	start.x = (*node)->pos->x;
	start.y = ((*node)->pos->y + 1 < len) ? (*node)->pos->y + 1 : 0;
	*node = ((*node)->next == env->arg) ? env->arg->next : (*node)->next;
	while ((*node)->pos->y != start.y || todo)
	{
		todo = FALSE;
		while ((*node)->pos->x != start.x)
		{
			if ((*node)->pos->y > (*node)->next->pos->y)
				start.y = 0;
			*node = ((*node)->next == env->arg)
				? env->arg->next : (*node)->next;
		}
	}
}

static t_lst					*ft_findy(t_env *env, int x)
{
	t_lst						*lst;

	lst = env->arg->prev;
	while (lst->pos->x != x)
		lst = lst->prev;
	return (lst);
}

void							ft_findprev(t_env *env, t_lst **node)
{
	int							todo;
	t_pos						start;

	if ((*node)->pos->y - 1 < 0)
	{
		*node = ft_findy(env, (*node)->pos->x);
		return ;
	}
	todo = TRUE;
	start.x = (*node)->pos->x;
	start.y = (*node)->pos->y - 1;
	*node = (*node)->prev;
	while ((*node)->pos->y != start.y || todo)
	{
		todo = FALSE;
		while ((*node)->pos->x != start.x)
			*node = ((*node)->next == env->arg)
				? env->arg->prev : (*node)->prev;
	}
}
