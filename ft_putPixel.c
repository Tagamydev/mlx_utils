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

/*
	pixelI = pixel index;
*/
void	ft_putPixel(t_img *img, t_point pixel, t_resolution window_res)
{
	unsigned int	*dst;
	float		pixelI;
	t_resolution	wndR;

	wndR = window_res;
	if (pixel.px >= 0 && pixel.py >= 0 && pixel.px < img->width && \
	pixel.py < img->height && pixel.py < wndR.height && pixel.px < wndR.width)
	{
		pixelI = ((pixel.py * img->line_size) + \
		((pixel.px * (img->bits_per_pixel / 8))));
		dst = (unsigned int *)(img->data_addr + (int)pixelI);
		*dst = pixel.color.hex;
	}
}
