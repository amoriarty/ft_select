/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 11:38:47 by alegent           #+#    #+#             */
/*   Updated: 2015/05/28 14:04:57 by alegent          ###   ########.fr       */
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

t_env					*ft_newenv(void);
t_pos					*ft_newpos(void);
t_lst					*ft_newlst(void);
t_env					*ft_sglt(void);
void					ft_handler(int n);
char					*ft_gettouch(void);

#endif
