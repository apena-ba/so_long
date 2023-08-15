/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en_movechecker1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:33:59 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 18:17:10 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	en_mup_schecker(int i, t_data *info)
{
	info->x_p = info->image.enemy_u->instances[i].x;
	info->y_p = info->image.enemy_u->instances[i].y - 3;
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
	return (1);
}

static int	en_mup_checker(int i, t_data *info)
{
	int	pos;

	info->x_p = info->image.enemy_u->instances[i].x;
	info->y_p = info->image.enemy_u->instances[i].y - 3;
	pos = 0;
	while (pos < info->map_info.enemy)
	{
		if (pos == i)
			pos++;
		if (pos > info->map_info.enemy)
			return (1);
		info->x_e = info->image.enemy_u->instances[pos].x;
		info->y_e = info->image.enemy_u->instances[pos].y;
		if (((info->x_p >= info->x_e && info->x_p <= info->x_e) || (info->x_p
					+ 48 > info->x_e && info->x_p + 48 < info->x_e + 64))
			&& (info->y_p > info->y_e && info->y_p < info->y_e + 64))
			return (0);
		pos++;
	}
	col_w_player_checker(0, i, info);
	return (en_mup_schecker(i, info));
}

static int	en_mdown_schecker(int i, t_data *info)
{
	int	pos;

	info->x_p = info->image.enemy_u->instances[i].x;
	info->y_p = info->image.enemy_u->instances[i].y + 3 + 48;
	pos = 0;
	while (pos < info->map_info.enemy)
	{
		if (pos == i)
			pos++;
		if (pos > info->map_info.enemy)
			return (1);
		info->x_e = info->image.enemy_u->instances[pos].x;
		info->y_e = info->image.enemy_u->instances[pos].y;
		if (((info->x_p >= info->x_e && info->x_p <= info->x_e) || (info->x_p
					+ 48 > info->x_e && info->x_p + 48 < info->x_e + 64))
			&& (info->y_p > info->y_e && info->y_p < info->y_e + 64))
			return (0);
		pos++;
	}
	return (1);
}

static int	en_mdown_checker(int i, t_data *info)
{
	info->x_p = info->image.enemy_u->instances[i].x;
	info->y_p = info->image.enemy_u->instances[i].y + 3 + 48;
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
	col_w_player_checker(1, i, info);
	return (en_mdown_schecker(i, info));
}

int	en_movechecker(int i, t_data *info)
{
	if (info->enemydir[i] == 0)
		return (en_mup_checker(i, info));
	else if (info->enemydir[i] == 1)
		return (en_mdown_checker(i, info));
	else if (info->enemydir[i] == 2)
		return (en_mleft_checker(i, info));
	return (en_mright_checker(i, info));
}
