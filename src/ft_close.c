/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:10:40 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/03 16:41:58 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close(t_fdf *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	while (i <= data->height)
	{
		free(data->z_matrix[i]);
		free(data->color_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data->color_matrix);
	free(data->img);
	free(data->mlx_ptr);
	free(data);
	exit(0);
	return (0);
}
