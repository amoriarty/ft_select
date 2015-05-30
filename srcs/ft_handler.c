/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 13:57:20 by alegent           #+#    #+#             */
/*   Updated: 2015/05/30 10:42:14 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_handler(int n)
{
	t_env					*env;

	if (n == SIGWINCH)
	{
		env = ft_sglt();
		if (tgetent(NULL, env->env) == ERROR)
			ft_perror();
		env->screen->x = tgetnum("co");
		env->screen->y = tgetnum("li");
		if (env->lenmax > env->screen->x || ft_lstlen() > env->screen->y)
		{
			ft_unsetenv();
			ft_perror();
		}
		else
			ft_plst();
	}
	else if (n == SIGQUIT || n == SIGINT)
	{
		ft_unsetenv();
		exit(EXIT_SUCCESS);
	}
}
