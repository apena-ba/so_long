/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:17:21 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/23 23:14:11 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	collision_up(t_data *info)
{
	info->x_p = info->image.player_u->instances[0].x;
	info->y_p = info->image.player_u->instances[0].y - 2;
	info->y = 0;
	info->coin_cont = 0;
	while (info->y < info->map_info.map_height)
	{
		info->x = 0;
		while (info->x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[info->y][info->x] == 'C')
			{
				if (((info->x_p > info->x * 64 && info->x_p < info->x * 64 + 64)
						|| (info->x_p + 48 > info->x * 64 && info->x_p
							+ 48 < info->x * 64 + 64)) && (info->y_p > info->y
						* 64 && info->y_p < info->y * 64 + 64))
					return (info->coin_cont);
				info->coin_cont++;
			}
			info->x++;
		}
		info->y++;
	}
	return (-1);
}

static int	collision_down(t_data *info)
{
	info->x_p = info->image.player_d->instances[0].x;
	info->y_p = info->image.player_d->instances[0].y + 2 + 48;
	info->y = 0;
	info->coin_cont = 0;
	while (info->y < info->map_info.map_height)
	{
		info->x = 0;
		while (info->x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[info->y][info->x] == 'C')
			{
				if (((info->x_p > info->x * 64 && info->x_p < info->x * 64 + 64)
						|| (info->x_p + 48 > info->x * 64 && info->x_p
							+ 48 < info->x * 64 + 64)) && (info->y_p > info->y
						* 64 && info->y_p < info->y * 64 + 64))
					return (info->coin_cont);
				info->coin_cont++;
			}
			info->x++;
		}
		info->y++;
	}
	return (-1);
}

static int	collision_left(t_data *info)
{
	info->x_p = info->image.player_l->instances[0].x - 2;
	info->y_p = info->image.player_l->instances[0].y;
	info->y = 0;
	info->coin_cont = 0;
	while (info->y < info->map_info.map_height)
	{
		info->x = 0;
		while (info->x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[info->y][info->x] == 'C')
			{
				if (((info->y_p >= info->y * 64 && info->y_p <= info->y * 64
							+ 64) || (info->y_p + 48 > info->y * 64 && info->y_p
							+ 48 < info->y * 64 + 64)) && (info->x_p > info->x
						* 64 && info->x_p < info->x * 64 + 64))
					return (info->coin_cont);
				info->coin_cont++;
			}
			info->x++;
		}
		info->y++;
	}
	return (-1);
}

static int	collision_right(t_data *info)
{
	info->x_p = info->image.player_r->instances[0].x + 2 + 48;
	info->y_p = info->image.player_r->instances[0].y;
	info->y = 0;
	info->coin_cont = 0;
	while (info->y < info->map_info.map_height)
	{
		info->x = 0;
		while (info->x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[info->y][info->x] == 'C')
			{
				if (((info->y_p >= info->y * 64 && info->y_p <= info->y * 64
							+ 64) || (info->y_p + 48 > info->y * 64 && info->y_p
							+ 48 < info->y * 64 + 64)) && (info->x_p > info->x
						* 64 && info->x_p < info->x * 64 + 64))
					return (info->coin_cont);
				info->coin_cont++;
			}
			info->x++;
		}
		info->y++;
	}
	return (-1);
}

int	collision_checker(int dir, t_data *info)
{
	if (dir == 0)
	{
		exit_collision_checker(dir, info);
		return (collision_up(info));
	}
	else if (dir == 1)
	{
		exit_collision_checker(dir, info);
		return (collision_down(info));
	}
	else if (dir == 2)
	{
		exit_collision_checker(dir, info);
		return (collision_left(info));
	}
	exit_collision_checker(dir, info);
	return (collision_right(info));
}
