/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:05:11 by alegent           #+#    #+#             */
/*   Updated: 2015/05/30 10:40:29 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_select(void)
{
	t_env					*env;
	t_lst					*node;
	char					*touch;

	env = ft_sglt();
	ft_lenmax();
	ft_plst();
	node = env->arg->next;
	while (*(touch = ft_gettouch()) != RETURN && node->next != env->arg)
	{
		if (*touch == ESC || *touch == DEL)
			ft_escape(&node);
	}
}
