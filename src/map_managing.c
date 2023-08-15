/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:39:00 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/25 16:49:37 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_toimage(int dir, t_data *info)
{
	info->image.player_u->instances[0].enabled = false;
	info->image.player_d->instances[0].enabled = false;
	info->image.player_l->instances[0].enabled = false;
	info->image.player_r->instances[0].enabled = false;
	if (dir == 0)
		info->image.player_u->instances[0].enabled = true;
	else if (dir == 1)
		info->image.player_d->instances[0].enabled = true;
	else if (dir == 2)
		info->image.player_l->instances[0].enabled = true;
	else if (dir == 3)
		info->image.player_r->instances[0].enabled = true;
}

static void	floor_drawer(t_data *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->map_info.map_height)
	{
		x = 0;
		while (x < info->map_info.map_lenght - 1)
		{
			mlx_image_to_window(info->mlx, info->image.floor, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

static void	ft_drawer(int x, int y, int c, t_data *info)
{
	if (c == '1')
		mlx_image_to_window(info->mlx, info->image.wall, x * 64, y * 64);
	else if (c == 'C')
		mlx_image_to_window(info->mlx, info->image.coin, x * 64, y * 64);
	else if (c == 'P')
	{
		mlx_image_to_window(info->mlx, info->image.player_u, x * 64, y * 64);
		mlx_image_to_window(info->mlx, info->image.player_r, x * 64, y * 64);
		mlx_image_to_window(info->mlx, info->image.player_l, x * 64, y * 64);
		mlx_image_to_window(info->mlx, info->image.player_d, x * 64, y * 64);
		move_toimage(1, info);
	}
}

void	open_map(t_data *info)
{
	int	y;
	int	x;
	int	c;

	y = 0;
	image_creator(info);
	floor_drawer(info);
	door_drawer(info);
	while (y < info->map_info.map_height)
	{
		x = 0;
		while (x < info->map_info.map_lenght)
		{
			c = info->map_info.map_data[y][x];
			ft_drawer(x, y, c, info);
			x++;
		}
		y++;
	}
}
