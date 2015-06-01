/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 20:42:31 by alegent           #+#    #+#             */
/*   Updated: 2015/06/01 20:46:57 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				ft_space(t_env *env, t_lst **node)
{
	if ((*node)->flag & REVERSE)
		(*node)->flag &= ~REVERSE;
	else
		(*node)->flag |= REVERSE;
	(*node)->flag &= ~UNDER;
	ft_update(*node);
	*node = ((*node)->next == env->arg) ? env->arg->next : (*node)->next;
	(*node)->flag |= UNDER;
	ft_update(*node);
}
