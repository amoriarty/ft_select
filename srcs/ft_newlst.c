/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 12:03:52 by alegent           #+#    #+#             */
/*   Updated: 2015/05/28 12:04:53 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_lst						*ft_newlst(void)
{
	t_lst					*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		ft_perror();
	new->entry = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
