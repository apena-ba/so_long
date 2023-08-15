/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_applier1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:25:59 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/25 21:24:54 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_enable(t_data *info)
{
	int	cont;

	cont = 0;
	while (cont < info->map_info.exit)
	{
		info->image.exit->instances[cont].enabled = false;
		info->image.exit_open->instances[cont].enabled = true;
		cont++;
	}
}

void	collision_apply(int pos, t_data *info)
{
	if (pos == -1)
		return ;
	if (info->image.coin->instances[pos].enabled == true)
	{
		info->image.coin->instances[pos].enabled = false;
		info->map_info.coins--;
	}
	if (info->map_info.coins == 0)
		exit_enable(info);
}

void	door_drawer(t_data *info)
{
	int	y;
	int	x;
	int	cont;

	y = 0;
	cont = 0;
	while (y < info->map_info.map_height)
	{
		x = 0;
		while (x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[y][x] == 'E')
			{
				mlx_image_to_window(info->mlx, info->image.exit_open, x * 64, y
					* 64);
				info->image.exit_open->instances[cont].enabled = false;
				mlx_image_to_window(info->mlx, info->image.exit, x * 64, y
					* 64);
				cont++;
			}
			x++;
		}
		y++;
	}
}

void	ft_exit_success(t_data *info)
{
	ft_printf("\033[0;32mYOU WIN!!\033[0m\n");
	ft_free_charpp(info->map_info.map_data);
	exit(1);
}
