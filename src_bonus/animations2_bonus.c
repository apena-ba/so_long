/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 22:00:18 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 22:13:56 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	fourth_door_an(t_data *info)
{
	int	i;

	i = 0;
	while (i < info->map_info.exit)
	{
		info->image.exit_nopen3->instances[i].enabled = false;
		info->image.exit_open->instances[i].enabled = true;
		i++;
	}
}

static void	third_door_an(t_data *info)
{
	int	i;

	i = 0;
	while (i < info->map_info.exit)
	{
		info->image.exit_nopen2->instances[i].enabled = false;
		info->image.exit_nopen3->instances[i].enabled = true;
		i++;
	}
}

static void	second_door_an(t_data *info)
{
	int	i;

	i = 0;
	while (i < info->map_info.exit)
	{
		info->image.exit_nopen1->instances[i].enabled = false;
		info->image.exit_nopen2->instances[i].enabled = true;
		i++;
	}
}

static void	first_door_an(t_data *info)
{
	int	i;

	i = 0;
	while (i < info->map_info.exit)
	{
		info->image.exit->instances[i].enabled = false;
		info->image.exit_nopen1->instances[i].enabled = true;
		i++;
	}
}

void	door_animation(t_data *info)
{
	int	i;

	i = 0;
	if (info->timer == 3 && !info->map_info.coins
		&& info->image.exit->instances[i].enabled == true)
		first_door_an(info);
	else if (info->timer == 6 && !info->map_info.coins
		&& info->image.exit_nopen1->instances[i].enabled == true)
		second_door_an(info);
	else if (info->timer == 9 && !info->map_info.coins
		&& info->image.exit_nopen2->instances[i].enabled == true)
		third_door_an(info);
	else if (info->timer == 12 && !info->map_info.coins
		&& info->image.exit_nopen3->instances[i].enabled == true)
		fourth_door_an(info);
	if (info->timer == 15)
		info->timer = 0;
}
