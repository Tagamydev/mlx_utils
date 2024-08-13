/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:22:04 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/11 13:22:07 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRENSENHAM_H
# define BRENSENHAM_H
# include "libft.h"
# include "T_Engine.h"
# include <math.h>

typedef struct s_bb{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	t_line	line;
}				t_bb;

void	drawLine(t_point f, t_point s, t_img *map_display);

#endif
