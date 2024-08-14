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
	pixel_i = pixel index;
*/
void	put_pixel(t_img *img, t_point pixel)
{
	unsigned int	*dst;
	float		pixel_i;

	if (pixel.px >= 0 && pixel.py >= 0 && pixel.px < img->resolution.width && \
	pixel.py < img->resolution.height && pixel.py)
	{
		pixel_i = ((pixel.py * img->line_size) + \
		((pixel.px * (img->bits_per_pixel / 8))));
		dst = (unsigned int *)(img->data_addr + (int)pixel_i);
		*dst = pixel.color.hex;
	}
}
