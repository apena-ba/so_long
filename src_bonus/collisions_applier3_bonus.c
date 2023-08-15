/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_applier3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:52:01 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 20:02:32 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	up_en_checker(t_data *info)
{
	int	pos;

	info->x_p = info->image.player_u->instances[0].x;
	info->y_p = info->image.player_u->instances[0].y - 1;
	pos = 0;
	while (pos < info->map_info.enemy)
	{
		info->x_e = info->image.enemy_u->instances[pos].x;
		info->y_e = info->image.enemy_u->instances[pos].y;
		if (((info->x_p >= info->x_e && info->x_p <= info->x_e) || (info->x_p
					+ 48 > info->x_e && info->x_p + 48 < info->x_e + 64))
			&& (info->y_p > info->y_e && info->y_p < info->y_e + 48))
			ft_exit_failure(info);
		pos++;
	}
}

static void	down_en_checker(t_data *info)
{
	int	pos;

	info->x_p = info->image.player_u->instances[0].x;
	info->y_p = info->image.player_u->instances[0].y + 1 + 48;
	pos = 0;
	while (pos < info->map_info.enemy)
	{
		info->x_e = info->image.enemy_u->instances[pos].x;
		info->y_e = info->image.enemy_u->instances[pos].y;
		if (((info->x_p >= info->x_e && info->x_p <= info->x_e) || (info->x_p
					+ 48 > info->x_e && info->x_p + 48 < info->x_e + 64))
			&& (info->y_p > info->y_e && info->y_p < info->y_e + 48))
			ft_exit_failure(info);
		pos++;
	}
}

static void	left_en_checker(t_data *info)
{
	int	pos;

	info->x_p = info->image.player_u->instances[0].x - 1;
	info->y_p = info->image.player_u->instances[0].y;
	pos = 0;
	while (pos < info->map_info.enemy)
	{
		info->x_e = info->image.enemy_u->instances[pos].x;
		info->y_e = info->image.enemy_u->instances[pos].y;
		if (((info->y_p >= info->y_e && info->y_p <= info->y_e) || (info->y_p
					+ 48 > info->y_e && info->y_p + 48 < info->y_e + 64))
			&& (info->x_p > info->x_e && info->x_p < info->x_e + 48))
			ft_exit_failure(info);
		pos++;
	}
}

static void	right_en_checker(t_data *info)
{
	int	pos;

	info->x_p = info->image.player_u->instances[0].x + 1 + 48;
	info->y_p = info->image.player_u->instances[0].y;
	pos = 0;
	while (pos < info->map_info.enemy)
	{
		info->x_e = info->image.enemy_u->instances[pos].x;
		info->y_e = info->image.enemy_u->instances[pos].y;
		if (((info->y_p >= info->y_e && info->y_p <= info->y_e) || (info->y_p
					+ 48 > info->y_e && info->y_p + 48 < info->y_e + 64))
			&& (info->x_p > info->x_e && info->x_p < info->x_e + 48))
			ft_exit_failure(info);
		pos++;
	}
}

void	enemy_collision_checker(int dir, t_data *info)
{
	if (dir == 0)
		return (up_en_checker(info));
	else if (dir == 1)
		return (down_en_checker(info));
	else if (dir == 2)
		return (left_en_checker(info));
	return (right_en_checker(info));
}
