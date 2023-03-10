/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:09:00 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/13 17:23:06 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create(t_fdf *data)
{
	data->zoom = 20;
	data->shift_x = LARG_FIN / 2.2;
	data->shift_y = ALT_FIN / 3;
	data->angle = 0.973599;
	data->z_scale = 2;
	data->dim = 1;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, LARG_FIN, ALT_FIN, "FDF");
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac != 2 || open(av[1], O_RDWR) == -1)
	{
		ft_printf("ERRORE\nAttenzione: scegliere mappa correttamente.\n");
		ft_printf("Per utilizzare scrivere: ./fdf maps/(scegli mappa)\n");
		return (0);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->img = (t_img *)malloc(sizeof(t_img));
	read_map(av[1], data);
	create(data);
	image(data);
	mlx_hook(data->win_ptr, 17, 0L, ft_close, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, deal_keys, data);
	mlx_loop(data->mlx_ptr);
}
