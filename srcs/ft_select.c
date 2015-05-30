/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:05:11 by alegent           #+#    #+#             */
/*   Updated: 2015/05/30 10:17:21 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_select(void)
{
	t_env					*env;
	t_lst					*node;
	t_lst					*tmp;
	char					*touch;

	env = ft_sglt();
	ft_lenmax();
	ft_plst();
	node = env->arg->next;
	while (*(touch = ft_gettouch()) != 13 && node != env->arg)
	{
		if (*touch == 27)
		{
			tmp = node->next;
			ft_deletenode(node);
			node = tmp;
			ft_lenmax();
			ft_plst();
		}
	}
}
