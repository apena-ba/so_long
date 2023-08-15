/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en_movechecker2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:49:12 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 18:17:27 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	en_mleft_schecker(int i, t_data *info)
{
	info->x_p = info->image.enemy_u->instances[i].x - 3;
	info->y_p = info->image.enemy_u->instances[i].y;
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
	return (1);
}

int	en_mleft_checker(int i, t_data *info)
{
	int	pos;

	info->x_p = info->image.enemy_u->instances[i].x - 3;
	info->y_p = info->image.enemy_u->instances[i].y;
	pos = 0;
	while (pos < info->map_info.enemy)
	{
		if (pos == i)
			pos++;
		if (pos > info->map_info.enemy)
			return (1);
		info->x_e = info->image.enemy_u->instances[pos].x;
		info->y_e = info->image.enemy_u->instances[pos].y;
		if (((info->y_p >= info->y_e && info->y_p <= info->y_e) || (info->y_p
					+ 64 > info->y_e && info->y_p + 64 < info->y_e + 64))
			&& (info->x_p > info->x_e && info->x_p < info->x_e + 64))
			return (0);
		pos++;
	}
	col_w_player_checker(2, i, info);
	return (en_mleft_schecker(i, info));
}

static int	en_mright_schecker(int i, t_data *info)
{
	info->x_p = info->image.enemy_u->instances[i].x + 3 + 48;
	info->y_p = info->image.enemy_u->instances[i].y;
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
	return (1);
}

int	en_mright_checker(int i, t_data *info)
{
	int	pos;

	info->x_p = info->image.enemy_u->instances[i].x + 3 + 48;
	info->y_p = info->image.enemy_u->instances[i].y;
	pos = 0;
	while (pos < info->map_info.enemy)
	{
		if (pos == i)
			pos++;
		if (pos > info->map_info.enemy)
			return (1);
		info->x_e = info->image.enemy_u->instances[pos].x;
		info->y_e = info->image.enemy_u->instances[pos].y;
		if (((info->y_p >= info->y_e && info->y_p <= info->y_e) || (info->y_p
					+ 64 > info->y_e && info->y_p + 64 < info->y_e + 64))
			&& (info->x_p > info->x_e && info->x_p < info->x_e + 64))
			return (0);
		pos++;
	}
	col_w_player_checker(3, i, info);
	return (en_mright_schecker(i, info));
}
