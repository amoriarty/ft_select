/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 14:18:20 by alegent           #+#    #+#             */
/*   Updated: 2015/05/28 14:31:47 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_insertnode(char *entry)
{
	t_env					*env;
	t_lst					*new;
	t_lst					*tmp;

	env = ft_sglt();
	new = ft_newlst();
	new->entry = entry;
	tmp = env->arg->next;
	while (tmp->next != env->arg)
		tmp = tmp->next;
	new->prev = tmp;
	new->next = tmp->next;
	tmp->next->prev = new;
	tmp->next = new;
}
