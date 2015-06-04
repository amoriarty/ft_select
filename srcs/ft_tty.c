/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tty.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 17:39:36 by alegent           #+#    #+#             */
/*   Updated: 2015/06/04 19:30:18 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int										ft_tty(void)
{
	static int							fd;

	if (!fd)
	{
		if ((fd = open(ttyname(ttyslot()), O_NOCTTY | O_RDWR)) == ERROR)
			ft_perror();
		if (!isatty(fd))
			ft_perror();
	}
	return (fd);
}
