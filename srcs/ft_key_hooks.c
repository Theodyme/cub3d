/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:52:00 by theophane         #+#    #+#             */
/*   Updated: 2024/03/07 14:53:30 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ------------------------------- keyrelease_hook() ---------------------------------- */
/*
**		parle d'elle même; est appelée dans mlx_hook() pour binder des touches à des actions.
**		est appelée quand on RELEASE une touche.
*/

int	keyrelease_hook(int keycode, t_mlx *data)
{
	if (keycode == KEY_Z)
        data->moves->forward = 0;
    if (keycode == KEY_S)
        data->moves->backward = 0;
    if (keycode == KEY_Q)
        data->moves->left = 0;
    if (keycode == KEY_D)
        data->moves->right = 0;
    if (keycode == KEY_LEFT)
        data->moves->rotate_left = 0;
    if (keycode == KEY_RIGHT)
    {
        data->moves->rotate_right = 0; //FAUT CHANGER LES TOUCHES
    }
    return (0);
}

/* ------------------------------- keypress_hook() ---------------------------------- */
/*
**		parle d'elle même; est appelée dans mlx_hook() pour binder des touches à des actions.
**		est appelée quand on PRESS une touche.
*/

int	keypress_hook(int keycode, t_mlx *data)
{
	if (keycode == XK_Escape)
		return (clear_all(data), 0);
	if (keycode == KEY_Z)
        data->moves->forward = 1;
    if (keycode == KEY_S)
        data->moves->backward = 1;
    if (keycode == KEY_Q)
        data->moves->left = 1;
    if (keycode == KEY_D)
        data->moves->right = 1;
    if (keycode == KEY_LEFT)
        data->moves->rotate_left = 1;
    if (keycode == KEY_RIGHT)
    {
        data->moves->rotate_right = 1;
    }
    return (0); //FAUT CHANGER LES TOUCHES
}