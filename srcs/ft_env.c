/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 14:38:29 by alegent           #+#    #+#             */
/*   Updated: 2015/06/02 18:31:00 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_setenv(void)
{
	t_env					*env;

	env = ft_sglt();
	if (!(env->env = getenv("TERM")))
		ft_puterror("ft_select", "TERM variable not found.");
	if (tgetent(NULL, env->env) == ERROR)
		ft_perror();
	if (tcgetattr(0, env->term) == ERROR)
		ft_perror();
	env->term->c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(0, TCSADRAIN, env->term) == ERROR)
		ft_perror();
	env->screen->x = tgetnum("co");
	env->screen->y = tgetnum("li");
	ft_putstr_fd(tgetstr("vi", NULL), ft_tty());
	signal(SIGWINCH, ft_handler);
	signal(SIGINT, ft_handler);
	signal(SIGQUIT, ft_handler);
}

void						ft_unsetenv(void)
{
	t_env					*env;

	env = ft_sglt();
	if (tcgetattr(0, env->term) == ERROR)
		ft_perror();
	env->term->c_lflag |= (ECHO | ICANON);
	if (tcsetattr(0, 0, env->term) == ERROR)
		ft_perror();
	ft_putstr_fd(tgetstr("ve", NULL), ft_tty());
}
