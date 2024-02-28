/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/28 21:38:41 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ------------------------------- ray_calculator() -------------------------------- */
/*
**		calcule les valeurs cameraX qui permettra de scale les valeurs de -1 à 1,
**      et l'orientation du rayon y et x (addition vectorielle + scaling sur cameraX).
*/

void    ray_calculator(int i, t_mlx *data)
{
    data->camerax = 2 * (double)i / (double)WINWIDTH - 1.0;
    printf("camerax = %f\n", data->camerax);
    printf("dir = (%f, %f)\n", data->dir->x, data->dir->y);
    printf("plane = (%f, %f)\n", data->plane->x, data->plane->y);
    printf("%f = %f + %f * %f\n", (data->dir->x + (data->plane->x * data->camerax)), data->dir->x, data->plane->x, data->camerax);
    data->ray->x = data->dir->x + data->plane->x * data->camerax;
    data->ray->y = data->dir->y + data->plane->y * data->camerax;
    // printf("ray = (%f, %f)\n", data->ray->x, data->ray->y);
}

/* ------------------------------- delta_calculator() -------------------------------- */
/*
**		calcule le deltaDistance - la distance d'un mur à l'autre en fonction de l'orientation
**      du rayon. (application de pythagore)
*/

void    delta_calculator(t_mlx *data)
{
    printf("ray = (%f, %f)\n", data->ray->x, data->ray->y);
    if (data->ray->x == 0)
        data->delta->x = 1;
    else if (data->ray->y == 0)
        data->delta->x = 0;
    else
        // data->delta->x = fabs(1 / data->ray->x);
        data->delta->x = sqrt(1 + (data->ray->y * data->ray->y) / (data->ray->x * data->ray->x));

    if (data->ray->x == 0)
        data->delta->y = 0;
    else if (data->ray->y == 0)
        data->delta->y = 1;
    else
        // data->delta->y = fabs(1 / data->ray->y);
        data->delta->y = sqrt(1 + (data->ray->x * data->ray->x) / (data->ray->y * data->ray->y));

}

/* ------------------------------- side_calculator() -------------------------------- */
/*
**		calcule la distance entre le joueur (position en double) et le bord de la case sur
**      laquelle il se trouve.
*/

void    side_calculator(t_mlx *data)
{
    if (data->ray->x < 0)
    {
        data->step->x = -1;
        data->side->x = (data->pos->x - (double)data->square->x) * data->delta->x;
    }
    else
    {
        data->step->x = 1;
        data->side->x = ((double)data->square->x + 1.0 - data->pos->x) * data->delta->x;
    }
    if (data->ray->y < 0)
    {
        data->step->y = -1;
        data->side->y = (data->pos->y - (double)data->square->y) * data->delta->y;
    }
    else
    {
        data->step->y = 1;
        data->side->y = ((double)data->square->y + 1.0 - data->pos->y) * data->delta->y;
    }
}

/* ------------------------------- hitpoint_calculator() -------------------------------- */
/*
**		trouve le mur le plus proche. c'est le coeur de l'algorithme DDA.
**      on ajoute systématiquement le delta pour avancer de limite de case en limite de case,
**      en prenant en compte le ratio de limites rencontrées en x pour une limite rencontrée en y,
**      ou vis-versa.
**      calcule ensuite perpWallDist, à savoir la distance entre le mur rencontré et le plan parallèle
**      sur lequel se situe le joueur.
*/

void    hitpoint_calculator(t_mlx *data)
{
    int hit;
    
    hit = 0;
    while (hit == 0)
    {
        if (data->side->x < data->side->y)
        {
            printf("side = (%f, %f)\n", data->side->x, data->side->y);
            data->side->x += data->delta->x;
            printf("side = (%f, %f)\n", data->side->x, data->side->y);
            data->square->x += data->step->x;
            data->sideHit = 0;
        }
        else
        {
            printf("side = (%f, %f)\n", data->side->x, data->side->y);
            data->side->y += data->delta->y;
            printf("side = (%f, %f)\n", data->side->x, data->side->y);
            data->square->y += data->step->y;
            data->sideHit = 1;
        }
        if (data->lvl->map[data->square->y][data->square->x] == '1')
            hit = 1;
    }
    printf("sideHit = %d\n", data->sideHit);
    // if (data->sideHit == 0)
    //     data->perpWallDist = data->side->x - data->delta->x;
    // else
    //     data->perpWallDist = data->side->y - data->delta->y;
    double	step_dist_x;
	double	step_dist_y;

	step_dist_x = (data->square->x - data->pos->x + (1 - data->step->x) / 2 );
	step_dist_y = (data->square->y - data->pos->y + (1 - data->step->y) / 2 );
	if (data->sideHit == 0)
		data->perpWallDist = step_dist_x / data->ray->x;
	else
		data->perpWallDist = step_dist_y / data->ray->y;
    return ;
}

/* --------------------------------- main_process() ------------------------------- */
/*
**		regroupe toutes les fonctions nécessaires pour effectuer les calculs des data,
**      dans une boucle qui parcourt l'écran horizontalement, afin de faire ces calculs
**      pour chaque pixel sur l'axe Y.
*/

void    main_process(t_mlx *data)
{
    int i;
    
    i = 0;
    data->plane->x = 0;
    data->plane->y = 0.75;
    data->dir->x = -1;
    data->dir->y = 0;
    map_printer(data->lvl->map, data->lvl->lenY);
    while (i < WINWIDTH)
    {
        printf("///////////////////\n");
        data->square->x = (int)data->pos->x;
        data->square->y = (int)data->pos->y;
        ray_calculator(i, data);
        // printf("ray = (%f, %f)\n", data->ray->x, data->ray->y);
        delta_calculator(data);
        printf("delta = (%f, %f)\n", data->delta->x, data->delta->y);
        side_calculator(data);
        printf("step = (%d, %d)\n", data->step->x, data->step->y);
        printf("side = (%f, %f)\n", data->side->x, data->side->y);
        hitpoint_calculator(data);
        printf("perpWallDist = (%f)\n", data->perpWallDist);
        wall_cast(i, data);
        printf("///////////////////\n");
        i++;
    }
}