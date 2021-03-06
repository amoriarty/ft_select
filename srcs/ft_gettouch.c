/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettouch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 14:01:24 by alegent           #+#    #+#             */
/*   Updated: 2015/06/05 14:31:31 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char						*ft_gettouch(void)
{
	char					*new;

	if (!(new = (char *)malloc(sizeof(char) * BUF + 1)))
		ft_perror();
	ft_bzero(new, BUF);
	if (read(0, new, BUF) < 0)
		ft_perror();
	return (new);
}
