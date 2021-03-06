/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 11:37:47 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 18:29:42 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int						main(int ac, char **av)
{
	int					i;

	if (ac == 1)
		return (EXIT_FAILURE);
	i = 0;
	ft_setenv();
	while (av[++i])
		ft_insertnode(av[i]);
	ft_select();
	ft_unsetenv();
	return (EXIT_SUCCESS);
}
