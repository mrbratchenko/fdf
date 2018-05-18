/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 20:59:56 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/19 21:00:19 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_node			*ft_node_init(void)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		free(node);
	node->x = 0;
	node->y = 0;
	node->z = 0;
	node->i = 0;
	node->temp_x = 0;
	node->temp_y = 0;
	node->temp_z = 0;
	node->centr_x = 0;
	node->centr_y = 0;
	node->dx = 0;
	node->dy = 0;
	node->sx = 0;
	node->sy = 0;
	node->x0 = 0;
	node->y0 = 0;
	node->x1 = 0;
	node->y1 = 0;
	node->next = NULL;
	return (node);
}

void			ft_ptrs_init(t_struct *ptrs)
{
	ptrs->mlx_ptr = mlx_init();
	ptrs->win_ptr = mlx_new_window(ptrs->mlx_ptr, 1000, 1000, "mlx 42");
	ptrs->img_ptr = mlx_new_image(ptrs->mlx_ptr, 1000, 1000);
	ptrs->img_a = 0;
	ptrs->img_b = 0;
	ptrs->img_c = 0;
	ptrs->image = mlx_get_data_addr(ptrs->img_ptr,
					&ptrs->img_a, &ptrs->img_b, &ptrs->img_c);
	ptrs->map_length = 0;
	ptrs->map_width = 0;
	ptrs->win_height = 1000;
	ptrs->node_ptr = NULL;
	ptrs->x_angle = 0.8;
	ptrs->y_angle = 0;
	ptrs->z_angle = 0.6;
	ptrs->zoom = 70;
	ptrs->color_ptr = 0;
	ptrs->moved_x = 0;
	ptrs->moved_y = 0;
	ptrs->color = 0;
	ptrs->shade = 1;
	ptrs->projectn = 0;
	ptrs->elevat = 0;
}
