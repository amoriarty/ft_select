/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 12:11:50 by alegent           #+#    #+#             */
/*   Updated: 2015/05/29 12:14:48 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int								ft_lstlen(void)
{
	int							res;
	t_env						*env;
	t_lst						*tmp;

	res = 0;
	env = ft_sglt();
	tmp = env->arg->next;
	while (tmp != env->arg)
	{
		res = (res < tmp->pos->y) ? tmp->pos->y : res;
		tmp = tmp->next;
	}
	return (res + 1);
}
