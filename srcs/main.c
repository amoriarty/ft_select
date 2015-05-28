/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 11:37:47 by alegent           #+#    #+#             */
/*   Updated: 2015/05/28 14:34:14 by alegent          ###   ########.fr       */
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

static void					ft_tmp(void)
{
	t_env					*env;
	t_lst					*tmp;

	env = ft_sglt();
	tmp = env->arg->next;
	while (tmp != env->arg)
	{
		ft_putendl(tmp->entry);
		tmp = tmp->next;
	}
}

int						main(int ac, char **av)
{
	int					i;

	if (ac == 1)
		return (EXIT_FAILURE);
	i = 0;
	ft_setenv();
	signal(SIGWINCH, ft_handler);
	while (av[++i])
		ft_insertnode(av[i]);
	ft_tmp();
	ft_gettouch();
	ft_unsetenv();
	return (EXIT_SUCCESS);
}
