/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 10:49:07 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 18:35:10 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					ft_pflag(char *entry, char flag)
{
	if (flag & REVERSE)
		ft_putstr_fd(tgetstr("mr", NULL), ft_tty());
	if (flag & UNDER)
		ft_putstr_fd(tgetstr("us", NULL), ft_tty());
	ft_putstr_fd(entry, ft_tty());
	if (flag & (UNDER | REVERSE))
		ft_putstr_fd(tgetstr("me", NULL), ft_tty());
}
