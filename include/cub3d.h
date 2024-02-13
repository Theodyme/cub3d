/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:42:25 by flplace           #+#    #+#             */
/*   Updated: 2024/02/07 16:17:26 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "colors.h"
# include "../lib/utils.h"
# include "../mlx/mlx.h"


# define WHITESPACES "\t\r\v\f\n "
# define TILESIZE 20

typedef struct s_map
{
	char	**map;
	int		y;
	int		x;
}				t_map;

typedef struct s_data {
	void	*img;
}				t_data;

typedef struct s_assets {
	t_data	*nwall;
	t_data	*swall;
	t_data	*wwall;
	t_data	*ewall;
	t_data	*bg;
	t_data	*start;
}				t_assets;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_map		*lvl;
	// t_assets	*assets;
}				t_mlx;

// ****************************************************************************
// UTILS

void    map_init();

// ****************************************************************************
// TITLE

#endif
