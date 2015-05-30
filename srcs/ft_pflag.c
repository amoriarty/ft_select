/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 10:49:07 by alegent           #+#    #+#             */
/*   Updated: 2015/05/30 10:59:49 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					ft_pflag(char *entry, char flag)
{
	if (flag & REVERSE)
		ft_putstr(tgetstr("mr", NULL));
	if (flag & UNDER)
		ft_putstr(tgetstr("us", NULL));
	ft_putstr(entry);
	if (flag & (UNDER | REVERSE))
		ft_putstr(tgetstr("me", NULL));
}
