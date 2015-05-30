/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 10:37:56 by alegent           #+#    #+#             */
/*   Updated: 2015/05/30 11:48:44 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_escape(t_lst **node)
{
	t_lst					*tmp;

	tmp = (*node)->next;
	ft_deletenode(*node);
	*node = tmp;
	(*node)->flag |= UNDER;
	ft_lenmax();
	ft_plst();
}
