/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:05:11 by alegent           #+#    #+#             */
/*   Updated: 2015/05/28 18:08:04 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
static void					tmp_pos(void)
{
	t_env					*env;
	t_lst					*tmp;

	env = ft_sglt();
	tmp = env->arg->next;
	while (tmp != env->arg)
	{
		printf("%s: x = %d, y = %d\n", tmp->entry, tmp->pos->x, tmp->pos->y);
		tmp = tmp->next;
	}
}
*/

void						ft_select(void)
{
	ft_lenmax();
	ft_plst();
	ft_gettouch();
}
