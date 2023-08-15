/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:11:55 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/26 21:11:58 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define SPEED 5

void	hook(void *info_)
{
	t_data	*info;

	info = info_;
	info->index = 0;
	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_W))
		while (movement_controller(0, info) == 1 && info->index <= SPEED)
			images_mover(0, info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_S))
		while (movement_controller(1, info) == 1 && info->index <= SPEED)
			images_mover(1, info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_A))
		while (movement_controller(2, info) == 1 && info->index <= SPEED)
			images_mover(2, info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_D))
		while (movement_controller(3, info) == 1 && info->index <= SPEED)
			images_mover(3, info);
}

void	action(t_data *info)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	info->mlx = mlx_init(info->map_info.map_lenght * 64 - 64,
			info->map_info.map_height * 64, "so_long", true);
	info->moves = 0;
	if (!info->mlx)
		exit(EXIT_FAILURE);
	open_map(info);
	mlx_loop_hook(info->mlx, hook, info);
	mlx_loop(info->mlx);
	mlx_terminate(info->mlx);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	info;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (ft_putstr_fd("Error\n", 2), 0);
		if (!map_checker(fd, argv[1], &info))
			return (ft_putstr_fd("Error\n", 2), 0);
		info.map_info.map_lenght = ft_strlen(info.map_info.map_data[0]);
		info.map_info.map_height = info.map_info.linebreaks + 1;
		action(&info);
	}
	else
		return (ft_putstr_fd("Error with arguments\n", 2), 0);
	ft_free_charpp(info.map_info.map_data);
	return (1);
}
