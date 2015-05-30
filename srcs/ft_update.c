/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 11:39:22 by alegent           #+#    #+#             */
/*   Updated: 2015/05/30 12:50:24 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					ft_update(t_lst *node)
{
	tputs(tgoto(tgetstr("cm", NULL), node->pos->x, node->pos->y), 1, ft_print);
	ft_pflag(node->entry, node->flag);
}
