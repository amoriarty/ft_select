/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 11:38:47 by alegent           #+#    #+#             */
/*   Updated: 2015/06/04 20:42:21 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include "struct.h"
# include "define.h"
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <signal.h>
# include <sys/termios.h>
# include <sys/ioctl.h>

void					ft_setenv(void);
void					ft_unsetenv(void);
t_env					*ft_newenv(void);
t_pos					*ft_newpos(void);
t_lst					*ft_newlst(void);
t_lst					*ft_newroot(void);
t_env					*ft_sglt(void);
void					ft_handler(int n);
void					ft_stophandler(int n);
char					*ft_gettouch(void);
void					ft_insertnode(char *entry);
void					ft_select(void);
void					ft_poscal(void);
void					ft_lenmax(void);
void					ft_plst(void);
int						ft_lstlen(void);
int						ft_print(int n);
void					ft_deletenode(t_lst *node);
void					ft_del(t_lst **node);
void					ft_pflag(char *entry, char flag);
void					ft_update(t_lst *node);
int						ft_direction(t_lst **node, char *touch);
int						ft_over(void);
void					ft_findnext(t_env *env, t_lst **node, int len);
void					ft_findprev(t_env *env, t_lst **node);
void					ft_space(t_env *env, t_lst **node);
int						ft_down(t_lst **node);
int						ft_right(t_lst **node);
int						ft_up(t_lst **node);
int						ft_left(t_lst **node);
int						ft_tty(void);
void					ft_sentres(void);

#endif
