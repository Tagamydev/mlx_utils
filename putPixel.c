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
void	putPixel(t_img *img, t_point pixel)
{
	unsigned int	*dst;
	float		pixelI;

	if (pixel.px >= 0 && pixel.py >= 0 && pixel.px < img->resolution.width && \
	pixel.py < img->resolution.height && pixel.py)
	{
		pixelI = ((pixel.py * img->line_size) + \
		((pixel.px * (img->bits_per_pixel / 8))));
		dst = (unsigned int *)(img->data_addr + (int)pixelI);
		*dst = pixel.color.hex;
	}
}
