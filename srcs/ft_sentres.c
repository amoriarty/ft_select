/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sentres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 20:40:25 by alegent           #+#    #+#             */
/*   Updated: 2015/06/04 20:59:33 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				ft_sentres(void)
{
	t_env			*env;
	t_lst			*lst;

	env = ft_sglt();
	lst = env->arg->next;
	while (lst != env->arg)
	{
		if (lst->flag & REVERSE)
		{
			ft_putstr(lst->entry);
			ft_putchar(EOL);
		}
		lst = lst->next;
	}
}
