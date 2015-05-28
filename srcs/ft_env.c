/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 14:38:29 by alegent           #+#    #+#             */
/*   Updated: 2015/05/28 14:43:04 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						ft_setenv(void)
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

void						ft_unsetenv(void)
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
