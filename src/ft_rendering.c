/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:47:08 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/24 17:48:35 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		ft_pixel_put(t_struct *ptrs, int x, int y)
{
	int i;

	i = (x * ptrs->img_a) + (y * ptrs->img_b);
	if (x < 0 || x > 999 || y < 0 || y > 999)
		return ;
	ptrs->image[i] = ptrs->color;
	ptrs->image[++i] = ptrs->color >> 8;
	ptrs->image[++i] = ptrs->color >> 16;
}

void		ft_positive_slope(t_node *node, t_struct *ptrs, int i)
{
	int d;
	int d1;
	int d2;
	int x;
	int y;

	d = (node->dy << 1) - node->dx;
	d1 = node->dy << 1;
	d2 = (node->dy - node->dx) << 1;
	ft_pixel_put(ptrs, node->x0, node->y0);
	x = node->x0 + node->sx;
	y = node->y0;
	while (i <= node->dx)
	{
		if (d > 0)
		{
			d += d2;
			y += node->sy;
		}
		else
			d += d1;
		ft_pixel_put(ptrs, x, y);
		i++;
		x += node->sx;
	}
}

void		ft_negative_slope(t_node *node, t_struct *ptrs, int i)
{
	int d;
	int d1;
	int d2;
	int x;
	int y;

	d = (node->dx << 1) - node->dy;
	d1 = node->dx << 1;
	d2 = (node->dx - node->dy) << 1;
	ft_pixel_put(ptrs, node->x0, node->y0);
	y = node->y0 + node->sy;
	x = node->x0;
	while (i <= node->dy)
	{
		if (d > 0)
		{
			d += d2;
			x += node->sx;
		}
		else
			d += d1;
		ft_pixel_put(ptrs, x, y);
		i++;
		y += node->sy;
	}
}

void		ft_line(int flag, t_node *node, t_node *current, t_struct *ptrs)
{
	int i;

	node->x0 = node->temp_x;
	node->y0 = node->temp_y;
	node->x1 = flag == 0 ? node->next->temp_x : current->temp_x;
	node->y1 = flag == 0 ? node->next->temp_y : current->temp_y;
	node->dx = abs(node->x1 - node->x0);
	node->dy = abs(node->y1 - node->y0);
	node->sx = node->x1 >= node->x0 ? 1 : -1;
	node->sy = node->y1 >= node->y0 ? 1 : -1;
	if (node->dy <= node->dx)
	{
		i = 1;
		ft_positive_slope(node, ptrs, i);
	}
	else
	{
		i = 1;
		ft_negative_slope(node, ptrs, i);
	}
}

void		ft_draw_lines(t_struct *ptrs, t_node *node)
{
	int		l;
	int		k;
	t_node	*current;

	k = 0;
	while (node && node->next && ++k)
	{
		l = 0;
		if (k % ptrs->map_length != 0 && node->next->next)
		{
			ptrs->color = node->z <= 0 && node->next->z <= 0 ?
				1 * ptrs->shade * 255 : 255 * ptrs->shade * 255;
			ft_line(0, node, current, ptrs);
		}
		current = node;
		while (l < ptrs->map_length && current->next && ++l)
			current = current->next;
		if (current->temp_x && current->temp_y)
		{
			ptrs->color = node->z <= 0 && current->z <= 0 ?
				1 * ptrs->shade * 255 : 255 * ptrs->shade * 255;
			ft_line(1, node, current, ptrs);
		}
		node = node->next;
	}
}
