/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newroot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 14:12:09 by alegent           #+#    #+#             */
/*   Updated: 2015/05/28 14:17:24 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_lst						*ft_newroot(void)
{
	t_lst					*new;

	new = ft_newlst();
	new->next = new;
	new->prev = new;
	return (new);
}
