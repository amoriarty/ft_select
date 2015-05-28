/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poscal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:14:36 by alegent           #+#    #+#             */
/*   Updated: 2015/05/28 17:47:19 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_poscal(void)
{
	int					x;
	int					y;
	int					col;
	t_env					*env;
	t_lst					*tmp;

	y = -1;
	env = ft_sglt();
	col = env->screen->x / env->lenmax;
	tmp = env->arg->next;
	while (tmp != env->arg)
	{
		y++;
		x = -1;
		while (tmp != env->arg && ++x < col)
		{
			tmp->pos->x = x * env->lenmax;
			tmp->pos->y = y;
			tmp = tmp->next;
		}
	}
}
