/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_over.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 11:31:39 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 11:29:21 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int						ft_over(void)
{
	int					over;
	t_env				*env;
	t_lst				*lst;

	over = 0;
	env = ft_sglt();
	lst = env->arg->next;
	while (lst != env->arg)
	{
		over++;
		lst = lst->next;
	}
	return (over);
}
