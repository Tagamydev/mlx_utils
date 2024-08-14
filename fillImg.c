/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putPixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:56:01 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/09 18:55:05 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	fill_img(t_img *img, t_color color)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i != img->resolution.height)
	{
		j = 0;
		while (j != img->resolution.width)
		{
			put_pixel(img, color_point(point(j, i), color));
			++j;
		}
		i++;
	}
}
