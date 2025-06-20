/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <alima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:22:17 by alima             #+#    #+#             */
/*   Updated: 2025/06/19 16:53:59 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_top_bottom(t_game *game)
{
	int x;

	x = 0;
	while (x < game->width_map)
	{
		if (!is_wall(game->map[0][x]))
			return (printf("Error! Top wall not solid\n"), 1);
		if (!is_wall(game->map[game->height_map - 1][x]))
			return (printf("Error! Bottom wall not solid\n"), 1);
		x++;
	}
	return (0);
}

int check_sides(t_game *game)
{
	int y;

	y = 0;
	while (y < game->height_map)
	{
		if (!is_wall(game->map[y][0]))
			return (printf("Error! Left wall not solid\n"), 1);
		if (!is_wall(game->map[y][game->width_map - 1]))
			return (printf("Error! Right wall not solid\n"), 1);
		y++;
	}
	return (0);
}
int check_near(t_game *game, int y, int x)
{
	if (y > 0 && !is_wall(game->map[y-1][x]) && !is_empty(game->map[y-1][x]))
		return (1);
	if (y < game->height_map - 1 && !is_wall(game->map[y+1][x]) && !is_empty(game->map[y+1][x]))
		return (1);
	if (x > 0 && !is_wall(game->map[y][x-1]) && !is_empty(game->map[y][x-1]))
		return (1);
	if (x < game->width_map - 1 && !is_wall(game->map[y][x+1]) && !is_empty(game->map[y][x+1]))
		return (1);
	return (0);
}

int check_interior(t_game *game)
{
	int x;
	int y;

	y = 1;
	while (y < game->height_map - 1)
	{
		x = 1;
		while (x < game->width_map - 1)
		{
			if (!is_valid_char(game->map[y][x]))
				return (printf("Error! Invalid char at %d,%d\n", x, y), 1);
			if (is_empty(game->map[y][x]) && check_near(game, y, x))
				return (printf("Error! Unenclosed space at %d,%d\n", x, y), 1);
			x++;
		}
		y++;
	}
	return (0);
}

int check_walls(t_game *game)
{
	if (check_top_bottom(game))
		return (1);
	if (check_sides(game))
		return (1);
	if (check_interior(game))
		return (1);
	return (0);
}
