/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:39:00 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 21:18:52 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	int	cont;

	cont = 0;
	y = 0;
	while (y < info->map_info.map_height)
	{
		x = 0;
		while (x < info->map_info.map_lenght - 1)
		{
			mlx_image_to_window(info->mlx, info->image.floor, x * 64, y * 64);
			if (info->map_info.map_data[y][x] == 'E')
			{
				print_door(cont, x, y, info);
				cont++;
			}
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
	else if (c == 'X')
	{
		mlx_image_to_window(info->mlx, info->image.enemy_u, x * 64, y * 64);
		mlx_image_to_window(info->mlx, info->image.enemy_r, x * 64, y * 64);
		mlx_image_to_window(info->mlx, info->image.enemy_l, x * 64, y * 64);
		mlx_image_to_window(info->mlx, info->image.enemy_d, x * 64, y * 64);
	}
}

static void	enable_enemy(t_data *info)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (x < info->map_info.enemy)
	{
		while (i < 6)
		{
			move_en_right(x, info);
			move_en_down(x, info);
			i++;
		}
		x++;
	}
	i = 0;
	while (i < info->map_info.enemy)
	{
		info->image.enemy_u->instances[i].enabled = false;
		info->image.enemy_d->instances[i].enabled = false;
		info->image.enemy_l->instances[i].enabled = false;
		info->image.enemy_r->instances[i].enabled = true;
		i++;
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
	enable_enemy(info);
	init_animation(info);
}
