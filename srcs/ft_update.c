/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 11:39:22 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 12:09:37 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					ft_update(t_lst *node)
{
	int					y;
	t_env				*env;;

	y = 0;
	env = ft_sglt();
	y = node->pos->y - env->scroll;
	if (y > -1 && y < env->screen->y)
	{
		tputs(tgoto(tgetstr("cm", NULL), node->pos->x, y), 1, ft_print);
		ft_pflag(node->entry, node->flag);
	}
}
