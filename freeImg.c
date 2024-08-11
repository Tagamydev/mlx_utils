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

void	freeImg(t_img *img)
{
	if (img)
	{
		if (img->img)
			free(img->img);
		if (img->path)
			free(img->path);
		if (img->data_addr)
			free(img->data_addr);
		if (img->pixel_addr)
			free(img->pixel_addr);
		ft_bzero(img, sizeof(t_img));
		free(img);
	}
}

