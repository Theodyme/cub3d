/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:10:26 by theophane         #+#    #+#             */
/*   Updated: 2024/03/14 21:15:34 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	move_forward(t_mlx *data)
{
	if (!data->moves->forward)
		return ;
	// printf("testing map[%d][%d] = [%c]\n", (int)(data->pos->x + data->dir->x * MOVE_SPEED), (int)(data->pos->y), data->lvl->map[(int)(data->pos->x + data->dir->x * MOVE_SPEED)][(int)data->pos->y]);
	// printf("line = [%s]\n", data->lvl->map[(int)(data->pos->x + data->dir->x * MOVE_SPEED)]);
	if (data->lvl->map[(int)data->pos->y][(int)(data->pos->x + data->dir->x * MOVE_SPEED)] &&
			(data->lvl->map[(int)data->pos->y][(int)(data->pos->x + data->dir->x * MOVE_SPEED)] != '1'))
		data->pos->x += data->dir->x * MOVE_SPEED;
	if (data->lvl->map[(int)(data->pos->y + data->dir->y * MOVE_SPEED)][(int)data->pos->x] &&
			(data->lvl->map[(int)(data->pos->y + data->dir->y * MOVE_SPEED)][(int)data->pos->x] != '1'))
		data->pos->y += data->dir->y * MOVE_SPEED;
}

void	move_backward(t_mlx *data)
{
	if (!data->moves->backward)
		return ;
	if (data->lvl->map[(int)data->pos->y][(int)(data->pos->x - data->dir->x * MOVE_SPEED)] &&
			(data->lvl->map[(int)data->pos->y][(int)(data->pos->x - data->dir->x * MOVE_SPEED)] != '1'))
		data->pos->x -= data->dir->x * MOVE_SPEED;
	if (data->lvl->map[(int)(data->pos->y - data->dir->y * MOVE_SPEED)][(int)data->pos->x] &&
			(data->lvl->map[(int)(data->pos->y - data->dir->y * MOVE_SPEED)][(int)data->pos->x] != '1'))
		data->pos->y -= data->dir->y * MOVE_SPEED;
}

void	move_right(t_mlx *data)
{
	if (!data->moves->right)
		return ;
	if (data->lvl->map[(int)data->pos->y][(int)(data->pos->x + data->plane->x * MOVE_SPEED)] &&
			(data->lvl->map[(int)data->pos->y][(int)(data->pos->x + data->plane->x * MOVE_SPEED)] != '1'))
		data->pos->x += data->plane->x * MOVE_SPEED;
	if (data->lvl->map[(int)(data->pos->y + data->plane->y * MOVE_SPEED)][(int)data->pos->x] &&
			(data->lvl->map[(int)(data->pos->y + data->plane->y * MOVE_SPEED)][(int)data->pos->x] != '1'))
		data->pos->y += data->plane->y * MOVE_SPEED;
}

void	move_left(t_mlx *data)
{
	if (!data->moves->left)
		return ;
	if (data->lvl->map[(int)data->pos->y][(int)(data->pos->x - data->plane->x * MOVE_SPEED)] &&
			(data->lvl->map[(int)data->pos->y][(int)(data->pos->x - data->plane->x * MOVE_SPEED)] != '1'))
		data->pos->x -= data->plane->x * MOVE_SPEED;
	if (data->lvl->map[(int)(data->pos->y - data->plane->y * MOVE_SPEED)][(int)data->pos->x] &&
			(data->lvl->map[(int)(data->pos->y - data->plane->y * MOVE_SPEED)][(int)data->pos->x] != '1'))
		data->pos->y -= data->plane->y * MOVE_SPEED;
}
// void	move_forward(t_mlx *data)
// {
// 	if (!data->moves->forward)
// 		return ;
// 	// printf("testing map[%d][%d] = [%c]\n", (int)(data->pos->x + data->dir->x * MOVE_SPEED), (int)(data->pos->y), data->lvl->map[(int)(data->pos->x + data->dir->x * MOVE_SPEED)][(int)data->pos->y]);
// 	// printf("line = [%s]\n", data->lvl->map[(int)(data->pos->x + data->dir->x * MOVE_SPEED)]);
// 	if (data->lvl->map[(int)(data->pos->x + data->dir->x * MOVE_SPEED)][(int)data->pos->y] &&
// 			(data->lvl->map[(int)(data->pos->x + data->dir->x * MOVE_SPEED)][(int)data->pos->y] != '1'))
// 		data->pos->x += data->dir->x * MOVE_SPEED;
// 	if (data->lvl->map[(int)data->pos->x][(int)(data->pos->y + data->dir->y * MOVE_SPEED)] &&
// 			(data->lvl->map[(int)data->pos->x][(int)(data->pos->y + data->dir->y * MOVE_SPEED)] != '1'))
// 		data->pos->y += data->dir->y * MOVE_SPEED;
// }

// void	move_backward(t_mlx *data)
// {
// 	if (!data->moves->backward)
// 		return ;
// 	if (data->lvl->map[(int)(data->pos->x - data->dir->x * MOVE_SPEED)][(int)data->pos->y] &&
// 			(data->lvl->map[(int)(data->pos->x - data->dir->x * MOVE_SPEED)][(int)data->pos->y] != '1'))
// 		data->pos->x -= data->dir->x * MOVE_SPEED;
// 	if (data->lvl->map[(int)data->pos->x][(int)(data->pos->y - data->dir->y * MOVE_SPEED)] &&
// 			(data->lvl->map[(int)data->pos->x][(int)(data->pos->y - data->dir->y * MOVE_SPEED)] != '1'))
// 		data->pos->y -= data->dir->y * MOVE_SPEED;
// }

// void	move_right(t_mlx *data)
// {
// 	if (!data->moves->right)
// 		return ;
// 	if (data->lvl->map[(int)(data->pos->x + data->plane->x * MOVE_SPEED)][(int)data->pos->y] &&
// 			(data->lvl->map[(int)(data->pos->x + data->plane->x * MOVE_SPEED)][(int)data->pos->y] != '1'))
// 		data->pos->x += data->plane->x * MOVE_SPEED;
// 	if (data->lvl->map[(int)data->pos->x][(int)(data->pos->y + data->plane->y * MOVE_SPEED)] &&
// 			(data->lvl->map[(int)data->pos->x][(int)(data->pos->y + data->plane->y * MOVE_SPEED)] != '1'))
// 		data->pos->y += data->plane->y * MOVE_SPEED;
// }

// void	move_left(t_mlx *data)
// {
// 	if (!data->moves->left)
// 		return ;
// 	if (data->lvl->map[(int)(data->pos->x - data->plane->x * MOVE_SPEED)][(int)data->pos->y] &&
// 			(data->lvl->map[(int)(data->pos->x - data->plane->x * MOVE_SPEED)][(int)data->pos->y] != '1'))
// 		data->pos->x -= data->plane->x * MOVE_SPEED;
// 	if (data->lvl->map[(int)data->pos->x][(int)(data->pos->y - data->plane->y * MOVE_SPEED)] &&
// 			(data->lvl->map[(int)data->pos->x][(int)(data->pos->y - data->plane->y * MOVE_SPEED)] != '1'))
// 		data->pos->y -= data->plane->y * MOVE_SPEED;
// }

void	rotation(t_mlx *data)
{
	double old;

    if (data->moves->rotate_left)
    {
		
		old = data->dir->y;
		data->dir->y = data->dir->x * sin(ROT_SPEED) + old * cos(ROT_SPEED);
		data->dir->x = data->dir->x * cos(ROT_SPEED) - old * sin(ROT_SPEED);
		old = data->plane->x;
		data->plane->x = data->plane->x * cos(ROT_SPEED) - data->plane->y * sin(ROT_SPEED);
		data->plane->y = old * sin(ROT_SPEED) + data->plane->y * cos(ROT_SPEED);
    }
	if (data->moves->rotate_right)
	{
		old = data->dir->y;
		data->dir->y = data->dir->x * sin(-ROT_SPEED) + old * cos(-ROT_SPEED);
		data->dir->x = data->dir->x * cos(-ROT_SPEED) - old * sin(-ROT_SPEED);
		old = data->plane->x;
		data->plane->x = data->plane->x * cos(-ROT_SPEED) - data->plane->y * sin(-ROT_SPEED);
		data->plane->y = old * sin(-ROT_SPEED) + data->plane->y * cos(-ROT_SPEED);
	}
}