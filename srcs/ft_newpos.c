/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 12:02:17 by alegent           #+#    #+#             */
/*   Updated: 2015/05/28 12:03:13 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_pos						*ft_newpos(void)
{
	t_pos					*new;

	if (!(new = (t_pos *)malloc(sizeof(t_pos))))
		ft_perror();
	new->x = 0;
	new->y = 0;
	return (new);
}
