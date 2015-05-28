/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_plst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:04:12 by alegent           #+#    #+#             */
/*   Updated: 2015/05/28 17:04:13 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					tmp_plst(void)
{
	t_env				*env;
	t_lst				*tmp;

	env = ft_sglt();
	tmp = env->arg->next;
	while (tmp != env->arg)
	{
		ft_putendl(tmp->entry);
		tmp = tmp->next;
	}
}
