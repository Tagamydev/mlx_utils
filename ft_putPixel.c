/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putPixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:56:01 by samusanc          #+#    #+#             */
/*   Updated: 2024/08/09 18:33:25 by samusanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	ft_putPixel(t_img *img, t_point pixel, t_resolution window_res)
{
	char		*dst;
	t_resolution	wndR;

	wndR = window_res;
	if (pixel.px >= 0 && pixel.py >= 0 && pixel.px < img->width && \
	pixel.py < img->height && pixel.py < wndR.height && pixel.px < wndR.width)
	{
		dst = (float)img->data_addr + ((pixel.py * img->line_size) + \
		((pixel.px * (img->bits_per_pixel / 8))));
		*(unsigned int *)dst = pixel.color.hex;
	}
}
