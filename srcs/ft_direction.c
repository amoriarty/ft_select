/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 11:16:03 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 14:07:34 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int						ft_direction(t_lst **node, char *touch)
{
	if (touch[0] == ESC)
	{
		if (touch[2] == DOWN)
			return (ft_down(node));
		else if (touch[2] == RIGHT)
			return (ft_right(node));
		else if (touch[2] == UP)
			return (ft_up(node));
		else if (touch[2] == LEFT)
			return (ft_left(node));
	}
	return (FAILURE);
}
