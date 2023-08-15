/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_aplier2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:53:39 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/26 13:49:12 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	up_checker(t_data *info)
{
	info->x_p = info->image.player_u->instances[0].x;
	info->y_p = info->image.player_u->instances[0].y - 2;
	info->y = 0;
	while (info->y < info->map_info.map_height)
	{
		info->x = 0;
		while (info->x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[info->y][info->x] == 'E'
				&& info->map_info.coins == 0)
			{
				if (((info->x_p > info->x * 64 && info->x_p < info->x * 64 + 64)
						|| (info->x_p + 48 > info->x * 64 && info->x_p
							+ 48 < info->x * 64 + 64)) && (info->y_p > info->y
						* 64 && info->y_p < info->y * 64 + 64))
					ft_exit_success(info);
			}
			info->x++;
		}
		info->y++;
	}
}

static void	down_checker(t_data *info)
{
	info->x_p = info->image.player_u->instances[0].x;
	info->y_p = info->image.player_u->instances[0].y + 2 + 48;
	info->y = 0;
	while (info->y < info->map_info.map_height)
	{
		info->x = 0;
		while (info->x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[info->y][info->x] == 'E'
				&& info->map_info.coins == 0)
			{
				if (((info->x_p > info->x * 64 && info->x_p < info->x * 64 + 64)
						|| (info->x_p + 48 > info->x * 64 && info->x_p
							+ 48 < info->x * 64 + 64)) && (info->y_p > info->y
						* 64 && info->y_p < info->y * 64 + 64))
					ft_exit_success(info);
			}
			info->x++;
		}
		info->y++;
	}
}

static void	left_checker(t_data *info)
{
	info->x_p = info->image.player_u->instances[0].x - 2;
	info->y_p = info->image.player_u->instances[0].y;
	info->y = 0;
	while (info->y < info->map_info.map_height)
	{
		info->x = 0;
		while (info->x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[info->y][info->x] == 'E'
				&& info->map_info.coins == 0)
			{
				if (((info->y_p >= info->y * 64 && info->y_p <= info->y * 64
							+ 64) || (info->y_p + 48 > info->y * 64 && info->y_p
							+ 48 < info->y * 64 + 64)) && (info->x_p > info->x
						* 64 && info->x_p < info->x * 64 + 64))
					ft_exit_success(info);
			}
			info->x++;
		}
		info->y++;
	}
}

static void	right_checker(t_data *info)
{
	info->x_p = info->image.player_u->instances[0].x + 2 + 48;
	info->y_p = info->image.player_u->instances[0].y;
	info->y = 0;
	while (info->y < info->map_info.map_height)
	{
		info->x = 0;
		while (info->x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[info->y][info->x] == 'E'
				&& info->map_info.coins == 0)
			{
				if (((info->y_p >= info->y * 64 && info->y_p <= info->y * 64
							+ 64) || (info->y_p + 48 > info->y * 64 && info->y_p
							+ 48 < info->y * 64 + 64)) && (info->x_p > info->x
						* 64 && info->x_p < info->x * 64 + 64))
					ft_exit_success(info);
			}
			info->x++;
		}
		info->y++;
	}
}

void	exit_collision_checker(int dir, t_data *info)
{
	if (dir == 0)
		return (up_checker(info));
	else if (dir == 1)
		return (down_checker(info));
	else if (dir == 2)
		return (left_checker(info));
	return (right_checker(info));
}
