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

t_img	*init_img(void *mlx, t_resolution res)
{
	t_img	*img;

	img = malloc(sizeof(t_img) * 1);
	if (!img)
		return (NULL);
	img->img = mlx_new_image(mlx, res.width, res.height);
	img->data_addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
	&(img->line_size), &(img->endian));
	img->alpha = 1;
	img->resolution = res;
	fill_img(img, color(black));
	return (img);
}
