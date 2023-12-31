/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:10:54 by W2Wizard          #+#    #+#             */
/*   Updated: 2022/09/17 17:50:23 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"

//= Public =//

void	*mlx_create_std_cursor(cursor_t type)
{
	GLFWcursor	*cursor;

	MLX_ASSERT(type >= MLX_CURSOR_ARROW && type < MLX_CURSOR_VRESIZE,
			"Invalid standart cursor type");
	if ((cursor = glfwCreateStandardCursor(type)))
		return (cursor);
	return ((void *)mlx_error(MLX_MEMFAIL));
}

void	*mlx_create_cursor(mlx_texture_t *texture)
{
	GLFWcursor	*cursor;

	MLX_NONNULL(texture);
	if ((cursor = glfwCreateCursor((GLFWimage *)texture, 0, 0)))
		return (cursor);
	return ((void *)mlx_error(MLX_MEMFAIL));
}

void	mlx_set_cursor(mlx_t *mlx, void *cursor)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(cursor);
	glfwSetCursor(mlx->window, cursor);
}

void	mlx_set_cursor_mode(mlx_t *mlx, mouse_mode_t mode)
{
	MLX_NONNULL(mlx);
	glfwSetInputMode(mlx->window, GLFW_CURSOR, mode);
}
