/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:52:00 by theophane         #+#    #+#             */
/*   Updated: 2024/03/15 17:49:27 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	keyrelease_hook(int keycode, t_mlx *data)
{
	if (keycode == KEY_W)
		data->moves->forward = 0;
	if (keycode == KEY_S)
		data->moves->backward = 0;
	if (keycode == KEY_A)
		data->moves->left = 0;
	if (keycode == KEY_D)
		data->moves->right = 0;
	if (keycode == KEY_LEFT)
		data->moves->rotate_left = 0;
	if (keycode == KEY_RIGHT)
	{
		data->moves->rotate_right = 0;
	}
	return (0);
}

int	keypress_hook(int keycode, t_mlx *data)
{
	if (keycode == KEY_ESCAPE)
		return (clear_all(data), 0);
	if (keycode == KEY_W)
		data->moves->forward = 1;
	if (keycode == KEY_S)
		data->moves->backward = 1;
	if (keycode == KEY_A)
		data->moves->left = 1;
	if (keycode == KEY_D)
		data->moves->right = 1;
	if (keycode == KEY_LEFT)
		data->moves->rotate_left = 1;
	if (keycode == KEY_RIGHT)
	{
		data->moves->rotate_right = 1;
	}
	return (0);
}
