/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 11:40:02 by alegent           #+#    #+#             */
/*   Updated: 2015/05/29 12:11:15 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct termios				t_term;
typedef struct s_env				t_env;
typedef struct s_lst				t_lst;
typedef struct s_pos				t_pos;

struct								s_env
{
	char							*env;
	t_term							*term;
	t_pos							*screen;
	t_lst							*arg;
	int								lenmax;
};

struct								s_lst
{
	char							*entry;
	t_pos							*pos;
	t_lst							*next;
	t_lst							*prev;
};

struct								s_pos
{
	int								x;
	int								y;
};

#endif
