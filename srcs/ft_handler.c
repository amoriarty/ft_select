/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 13:57:20 by alegent           #+#    #+#             */
/*   Updated: 2015/06/04 20:32:58 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_stophandler(int n)
{
	char					cp[2];

	if (n == SIGTSTP)
	{
		cp[0] = 032;
		cp[1] = 0;
		signal(SIGTSTP, SIG_DFL);
		ioctl(ft_tty(), TIOCSTI, cp);
		ft_unsetenv();
	}
	if (n == SIGCONT)
	{
		signal(SIGTSTP, ft_stophandler);
		ft_setenv();
		ft_plst();
	}
}

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
			return ;
		else
		{
			env->scroll = 0;
			ft_plst();
		}
	}
	if (n == SIGQUIT || n == SIGINT)
	{
		ft_unsetenv();
		exit(EXIT_FAILURE);
	}
}
