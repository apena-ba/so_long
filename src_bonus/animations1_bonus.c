/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:14:39 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 20:36:37 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_moves(t_data *info)
{
	char	*joined;
	char	*num;

	num = ft_itoa(info->moves);
	joined = ft_strjoin("Moves : ", num);
	mlx_delete_image(info->mlx, info->moves_text);
	info->moves_text = mlx_put_string(info->mlx, joined, 20,
			info->map_info.map_height * 64 + 22);
	free(num);
	free(joined);
}

void	enemy_moving(t_data *info)
{
	int	i;

	i = 0;
	while (i < info->map_info.enemy)
	{
		move_enemy(i, info);
		i++;
	}
}

void	init_animation(t_data *info)
{
	int	i;
	int	x;

	x = 0;
	while (x < 10)
	{
		i = 0;
		while (i < info->coin_total)
		{
			info->image.coin->instances[i].y--;
			i++;
		}
		x++;
	}
}

int	*en_dir_creator(t_data *info)
{
	int	*new_array;
	int	i;

	srand(time(NULL));
	new_array = ft_calloc(info->map_info.enemy, sizeof(int));
	i = 0;
	while (i < info->map_info.enemy)
	{
		new_array[i] = rand() % 4;
		i++;
	}
	return (new_array);
}
