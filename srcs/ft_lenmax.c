/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:17:25 by alegent           #+#    #+#             */
/*   Updated: 2015/05/29 12:05:01 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					ft_lenmax(void)
{
	t_env				*env;
	t_lst				*tmp;

	env = ft_sglt();
	env->lstlen = 0;
	tmp = env->arg->next;
	while (tmp != env->arg)
	{
		env->lenmax = ((int)ft_strlen(tmp->entry) > env->lenmax) ?
			ft_strlen(tmp->entry) : env->lenmax;
		env->lstlen++;
		tmp = tmp->next;
	}
	env->lenmax++;
}
