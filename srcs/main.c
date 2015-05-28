/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 11:37:47 by alegent           #+#    #+#             */
/*   Updated: 2015/05/28 14:05:11 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void					ft_setenv(void)
{
	t_env					*env;

	env = ft_sglt();
	if (tgetent(NULL, (env->env = getenv("TERM"))) == ERROR)
		ft_perror();
	if (tcgetattr(0, env->term) == ERROR)
		ft_perror();
	env->term->c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(0, TCSADRAIN, env->term) == ERROR)
		ft_perror();
	env->screen->x = tgetnum("co");
	env->screen->y = tgetnum("li");
	ft_putstr(tgetstr("vi", NULL));
}

static void					ft_unsetenv(void)
{
	t_env					*env;

	env = ft_sglt();
	if (tcgetattr(0, env->term) == ERROR)
		ft_perror();
	env->term->c_lflag |= (ECHO | ICANON);
	if (tcsetattr(0, 0, env->term) == ERROR)
		ft_perror();
	ft_putstr(tgetstr("ve", NULL));
}

int						main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_setenv();
	signal(SIGWINCH, ft_handler);
	ft_gettouch();
	ft_unsetenv();
	return (EXIT_SUCCESS);
}
