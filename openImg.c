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

static t_img	*free_open_img(t_img *img)
{
	free_img(img);
	return (NULL);
}

static t_img	*open_img_utils(t_img *img, void *mlx, char *path)
{
	char	*tmp;

	tmp = NULL;
	img->img = mlx_xpm_file_to_image(mlx, path, (int *)&img->resolution.width, (int *)&img->resolution.height);
	if (!img->img)
		return (free_open_img(img));
	img->data_addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_size), &(img->endian));
	if (!img->data_addr)
		return (free_open_img(img));
	img->pixel_addr = (int *)mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_size), &(img->endian));
	if (!img->pixel_addr)
		return (free_open_img(img));
	tmp = ft_strdup(path);
	if (!tmp)
		return (free_open_img(img));
	return (img);
}

t_img	*open_img(void *mlx, char *path)
{
	t_img	*img;

	if (!path)
		return (NULL);
	img = malloc(sizeof(t_img) * 1);
	if (!img)
		return (NULL);
	ft_bzero(img, sizeof(t_img));
	if (!open_img_utils(img, mlx, path))
		return (NULL);
	return (img);
}
