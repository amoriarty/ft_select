/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 11:38:47 by alegent           #+#    #+#             */
/*   Updated: 2015/05/29 12:08:14 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include "struct.h"
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <signal.h>
# include <sys/termios.h>
# define BUF 3
# define REG 0
# define UNDER 1
# define REVERSE 2
# define BOTH 3

void					ft_setenv(void);
void					ft_unsetenv(void);
t_env					*ft_newenv(void);
t_pos					*ft_newpos(void);
t_lst					*ft_newlst(void);
t_lst					*ft_newroot(void);
t_env					*ft_sglt(void);
void					ft_handler(int n);
char					*ft_gettouch(void);
void					ft_insertnode(char *entry);
void					ft_select(void);
void					ft_poscal(void);
void					ft_lenmax(void);
void					ft_plst(void);

/*
** FONCTIONS TEMPORAIRE
*/

void					tmp_plst(void);
int						ft_print(int n);

#endif
