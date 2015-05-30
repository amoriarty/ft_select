/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettouch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 14:01:24 by alegent           #+#    #+#             */
/*   Updated: 2015/05/30 11:04:08 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

unsigned char						*ft_gettouch(void)
{
	unsigned char				*new;

	if (!(new = (unsigned char *)malloc(sizeof(unsigned char) * BUF + 1)))
		ft_perror();
	new[BUF] = 0;
	if (read(0, new, BUF) <= 0)
		ft_perror();
	return (new);
}
