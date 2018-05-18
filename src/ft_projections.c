/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:46:50 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/24 17:46:53 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		ft_paralel_projection(t_struct *ptrs, t_node *node)
{
	while (node && node->next)
	{
		ft_axis_rotation(ptrs, node);
		ptrs->zoom == 0 ? ptrs->zoom = 1 : 0;
		node->temp_z = ptrs->win_height / ptrs->zoom;
		node->temp_x = node->temp_x * node->temp_z + (ptrs->win_height / 2);
		node->temp_y = node->temp_y * node->temp_z + (ptrs->win_height / 2);
		node->i = (node->temp_x * ptrs->img_a) + (node->temp_y * ptrs->img_b);
		node = node->next;
	}
}

void		ft_perspective_projection(t_struct *ptrs, t_node *node)
{
	double proj_z;

	proj_z = 0;
	while (node && node->next)
	{
		ft_axis_rotation(ptrs, node);
		proj_z = ptrs->zoom - node->temp_z;
		if (proj_z == 0)
			proj_z = 1;
		node->temp_z = ptrs->win_height / proj_z;
		node->temp_x = node->temp_x * node->temp_z + (ptrs->win_height / 2);
		node->temp_y = node->temp_y * node->temp_z + (ptrs->win_height / 2);
		node->i = (node->temp_x * ptrs->img_a) + (node->temp_y * ptrs->img_b);
		node = node->next;
	}
}

void		ft_axis_rotation(t_struct *ptrs, t_node *node)
{
	node->centr_x = (node->x - ptrs->map_length / 2);
	node->centr_y = (node->y - ptrs->map_width / 2);
	node->temp_x =
		node->centr_x * cos(ptrs->z_angle) - node->centr_y * sin(ptrs->z_angle);
	node->temp_y =
		node->centr_x * sin(ptrs->z_angle) + node->centr_y * cos(ptrs->z_angle);
	node->temp_y =
		node->temp_y * cos(-ptrs->x_angle) + node->z * sin(-ptrs->x_angle);
	node->temp_z =
		node->temp_y * sin(ptrs->x_angle) + node->z * cos(ptrs->x_angle);
	node->temp_x = node->temp_x + ptrs->moved_x;
	node->temp_y = node->temp_y + ptrs->moved_y;
}
