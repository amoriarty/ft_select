/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newterm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 12:05:08 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 12:03:47 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env						*ft_newenv(void)
{
	t_env					*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		ft_perror();
	if (!(new->term = (t_term *)malloc(sizeof(t_term))))
		ft_perror();
	new->env = NULL;
	new->screen = ft_newpos();
	new->scroll = 0;
	new->arg = ft_newroot();
	new->lenmax = 0;
	return (new);
}
