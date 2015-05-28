/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:17:25 by alegent           #+#    #+#             */
/*   Updated: 2015/05/28 17:44:07 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					ft_lenmax(void)
{
	int				i;
	t_env				*env;
	t_lst				*tmp;

	i = 0;
	env = ft_sglt();
	env->lstlen = 0;
	tmp = env->arg->next;
	while (tmp != env->arg)
	{
		env->lenmax = ((i = ft_strlen(tmp->entry)) > env->lenmax) ? i : env->lenmax;
		env->lstlen++;
		tmp = tmp->next;
	}
	env->lenmax++;
}
