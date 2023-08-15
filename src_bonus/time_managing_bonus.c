/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_managing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:24:30 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 22:00:58 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	up_levitation(t_data *info)
{
	int	i;

	i = 0;
	if (info->levitate == 0)
	{
		info->ident = 1;
		return ;
	}
	while (i < info->coin_total)
	{
		info->image.coin->instances[i].y--;
		i++;
	}
	info->levitate--;
}

static void	down_levitation(t_data *info)
{
	int	i;

	i = 0;
	if (info->levitate == 20)
	{
		info->ident = 2;
		return ;
	}
	while (i < info->coin_total)
	{
		info->image.coin->instances[i].y++;
		i++;
	}
	info->levitate++;
}

static void	levitation(t_data *info)
{
	int	i;

	i = 0;
	if (info->ident == 1)
		down_levitation(info);
	else
		up_levitation(info);
}

void	ft_time_manager(t_data *info)
{
	info->timer++;
	if (info->timer % 2 == 0)
	{
		enemy_moving(info);
		levitation(info);
	}
	door_animation(info);
}
