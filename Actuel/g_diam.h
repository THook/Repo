/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:51:33 by hvillain          #+#    #+#             */
/*   Updated: 2014/03/24 16:57:35 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		G_DIAM_H
# define	G_DIAM_H

typedef struct			s_art
{
		char			*name;
		int				db;
		struct s_art	*next;
}						t_art;

typedef struct			s_struct
{
	t_art				*art;
}						t_struct;

# endif

