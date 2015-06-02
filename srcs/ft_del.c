/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 12:24:54 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 11:27:27 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_del(t_lst **node)
{
	t_env					*env;
	t_lst					*tmp;

	env = ft_sglt();
	tmp = ((*node)->next == env->arg) ? env->arg->next : (*node)->next;
	ft_deletenode(*node);
	*node = tmp;
	(*node)->flag |= UNDER;
	ft_lenmax();
	ft_plst();
}
