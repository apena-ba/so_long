/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:55:10 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/26 20:26:22 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	move_up(t_data *info)
{
	info->x_p = info->image.player_u->instances[0].x;
	info->y_p = info->image.player_u->instances[0].y - 2;
	info->y = 0;
	while (info->y < info->map_info.map_height)
	{
		info->x = 0;
		while (info->x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[info->y][info->x] == '1')
			{
				if (((info->x_p > info->x * 64 && info->x_p < info->x * 64 + 64)
						|| (info->x_p + 48 > info->x * 64 && info->x_p
							+ 48 < info->x * 64 + 64)) && (info->y_p > info->y
						* 64 && info->y_p < info->y * 64 + 64))
					return (0);
			}
			info->x++;
		}
		info->y++;
	}
	collision_apply(collision_checker(0, info), info);
	return (1);
}

static int	move_down(t_data *info)
{
	info->x_p = info->image.player_d->instances[0].x;
	info->y_p = info->image.player_d->instances[0].y + 2 + 48;
	info->y = 0;
	while (info->y < info->map_info.map_height)
	{
		info->x = 0;
		while (info->x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[info->y][info->x] == '1')
				if (((info->x_p > info->x * 64 && info->x_p < info->x * 64 + 64)
						|| (info->x_p + 48 > info->x * 64 && info->x_p
							+ 48 < info->x * 64 + 64)) && (info->y_p > info->y
						* 64 && info->y_p < info->y * 64 + 64))
					return (0);
			info->x++;
		}
		info->y++;
	}
	collision_apply(collision_checker(1, info), info);
	return (1);
}

static int	move_left(t_data *info)
{
	info->x_p = info->image.player_l->instances[0].x - 2;
	info->y_p = info->image.player_l->instances[0].y;
	info->y = 0;
	while (info->y < info->map_info.map_height)
	{
		info->x = 0;
		while (info->x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[info->y][info->x] == '1')
				if (((info->y_p > info->y * 64 && info->y_p < info->y * 64 + 64)
						|| (info->y_p + 48 > info->y * 64 && info->y_p
							+ 48 < info->y * 64 + 64)) && (info->x_p > info->x
						* 64 && info->x_p < info->x * 64 + 64))
					return (0);
			info->x++;
		}
		info->y++;
	}
	collision_apply(collision_checker(2, info), info);
	return (1);
}

static int	move_right(t_data *info)
{
	info->x_p = info->image.player_r->instances[0].x + 2 + 48;
	info->y_p = info->image.player_r->instances[0].y;
	info->y = 0;
	while (info->y < info->map_info.map_height)
	{
		info->x = 0;
		while (info->x < info->map_info.map_lenght)
		{
			if (info->map_info.map_data[info->y][info->x] == '1')
				if (((info->y_p > info->y * 64 && info->y_p < info->y * 64 + 64)
						|| (info->y_p + 48 > info->y * 64 && info->y_p
							+ 48 < info->y * 64 + 64)) && (info->x_p > info->x
						* 64 && info->x_p < info->x * 64 + 64))
					return (0);
			info->x++;
		}
		info->y++;
	}
	collision_apply(collision_checker(3, info), info);
	return (1);
}

int	movement_controller(int dir, t_data *info)
{
	info->index++;
	if (dir == 0)
		return (move_toimage(dir, info), move_up(info));
	else if (dir == 1)
		return (move_toimage(dir, info), move_down(info));
	else if (dir == 2)
		return (move_toimage(dir, info), move_left(info));
	return (move_toimage(dir, info), move_right(info));
}
