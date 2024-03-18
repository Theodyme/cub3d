/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/18 12:39:54 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* --------------------- ray_calculator() ---------------------- */
/*
**		calcule les valeurs cameraX qui permettra
         de scale les valeurs de -1 à 1,
**      et l'orientation du rayon y
        et x (addition vectorielle + scaling sur cameraX).
*/

void	ray_calculator(int x, t_mlx *data)
{
	data->camerax = 2 * (double)x / (double)WINWIDTH - 1.0;
	data->ray->x = data->dir->x + data->plane->x * data->camerax;
	data->ray->y = data->dir->y + data->plane->y * data->camerax;
}

/* --------------------- delta_calculator() --------------------- */
/*
**		calcule le deltaDistance - la distance d'un mur
        à l'autre en fonction de l'orientation
**      du rayon. (application de pythagore)
*/

void	delta_calculator(t_mlx *data)
{
	if (data->ray->x == 0)
		data->delta->x = 1;
	else if (data->ray->y == 0)
		data->delta->x = 0;
	else
		data->delta->x = sqrt(1 + (data->ray->y * data->ray->y) / (data->ray->x
					* data->ray->x));
	if (data->ray->x == 0)
		data->delta->y = 0;
	else if (data->ray->y == 0)
		data->delta->y = 1;
	else
		data->delta->y = sqrt(1 + (data->ray->x * data->ray->x) / (data->ray->y
					* data->ray->y));
}

/* ------------------------------- side_calculator() ---------------------- */
/*
**		calcule la distance entre le joueur (position en double)
         et le bord de la case sur
**      laquelle il se trouve.
*/

void	side_calculator(t_mlx *data)
{
	if (data->ray->x < 0)
	{
		data->step->x = -1;
		data->side->x = (data->pos->x - (double)data->square->x)
			* data->delta->x;
	}
	else
	{
		data->step->x = 1;
		data->side->x = ((double)data->square->x + 1.0 - data->pos->x)
			* data->delta->x;
	}
	if (data->ray->y < 0)
	{
		data->step->y = -1;
		data->side->y = (data->pos->y - (double)data->square->y)
			* data->delta->y;
	}
	else
	{
		data->step->y = 1;
		data->side->y = ((double)data->square->y + 1.0 - data->pos->y)
			* data->delta->y;
	}
}
/* -------------------------- pwdist_calculator() ---------------------- */
/*
**		calcule la distance entre le point d'impact sur le mur
**		et la parallele au mur sur laquelle se trouve le joueur.
**		Cette manipulation sert notamment a corriger l'effet
**		fisheye.
*/

void	pwdist_calculator(t_mlx *data, t_vector *step_dist)
{
	step_dist->x = (data->square->x - data->pos->x + (1 - data->step->x) / 2);
	step_dist->y = (data->square->y - data->pos->y + (1 - data->step->y) / 2);
	if (data->sideHit == 0)
		data->pwdist = step_dist->x / data->ray->x;
	else
		data->pwdist = step_dist->y / data->ray->y;
	free(step_dist);
}

/* ---------------------- hitpoint_calculator() ---------------------- */
/*
**		trouve le mur le plus proche. c'est le coeur de l'algorithme DDA.
**      on ajoute systématiquement le delta pour avancer
        de limite de case en limite de case,
**      en prenant en compte le ratio de limites
        rencontrées en x pour une limite rencontrée en y,
**      ou vis-versa.
**      calcule ensuite pwdist, à savoir la distance
        entre le mur rencontré et le plan parallèle
**      sur lequel se situe le joueur.
*/

void	hitpoint_calculator(t_mlx *data)
{
	int		hit;
	t_vector	*step_dist;

	hit = 0;
	step_dist = malloc(sizeof(t_vector));
	while (hit == 0)
	{
		if (data->side->x < data->side->y)
		{
			data->side->x += data->delta->x;
			data->square->x += data->step->x;
			data->sideHit = 0;
		}
		else
		{
			data->side->y += data->delta->y;
			data->square->y += data->step->y;
			data->sideHit = 1;
		}
		if (data->lvl->map[data->square->y][data->square->x] == '1')
			hit = 1;
	}
	pwdist_calculator(data, step_dist);
	return ;
}
