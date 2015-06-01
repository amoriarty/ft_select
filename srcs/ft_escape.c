/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 10:37:56 by alegent           #+#    #+#             */
/*   Updated: 2015/06/01 11:36:47 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_escape(t_lst **node)
{
	t_env					*env;
	t_lst					*tmp;

	env = ft_sglt();
	tmp = ((*node)->next == env->arg)? env->arg->next : (*node)->next;
	ft_deletenode(*node);
	*node = tmp;
	(*node)->flag |= UNDER;
	ft_lenmax();
	ft_plst();
}
