/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:56:37 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/24 16:56:39 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int				ft_mouse_close(void)
{
	exit(0);
}

static void		ft_put_and_free_str(t_struct *ptrs, char *free_str,
															char *str, int i)
{
	free(free_str);
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 50, i, 0xffffff, str);
	free(str);
}

static void		ft_strings(t_struct *ptrs, char *free_str, char *str)
{
	int i;

	i = 50;
	str = ft_itoa(ptrs->x_angle * 10);
	free_str = str;
	str = ft_strjoin("x rotation: ", free_str);
	ft_put_and_free_str(ptrs, free_str, str, i);
	str = ft_itoa(ptrs->z_angle * 10);
	free_str = str;
	str = ft_strjoin("z rotation: ", free_str);
	ft_put_and_free_str(ptrs, free_str, str, i + 25);
	str = ft_itoa(ptrs->moved_x / 2);
	free_str = str;
	str = ft_strjoin("x movement: ", free_str);
	ft_put_and_free_str(ptrs, free_str, str, i + 50);
	str = ft_itoa(ptrs->moved_y / 2 * -1);
	free_str = str;
	str = ft_strjoin("y movement: ", free_str);
	ft_put_and_free_str(ptrs, free_str, str, i + 75);
	str = ft_itoa(ptrs->zoom);
	free_str = str;
	str = ft_strjoin("distance: ", free_str);
	ft_put_and_free_str(ptrs, free_str, str, i + 100);
}

static void		ft_keys(int key, t_struct *ptrs)
{
	if (key == 53)
	{
		mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
		exit(0);
	}
	key == 126 ? ptrs->x_angle += 0.05 : 0;
	key == 125 ? ptrs->x_angle -= 0.05 : 0;
	key == 124 ? ptrs->z_angle += 0.05 : 0;
	key == 123 ? ptrs->z_angle -= 0.05 : 0;
	key == 78 ? ptrs->zoom += 5 : 0;
	key == 69 ? ptrs->zoom -= 5 : 0;
	key == 2 ? ptrs->moved_x += 2 : 0;
	key == 0 ? ptrs->moved_x -= 2 : 0;
	key == 1 ? ptrs->moved_y += 2 : 0;
	key == 13 ? ptrs->moved_y -= 2 : 0;
	if (key == 49)
	{
		ptrs->shade = ptrs->shade > 255 ? 1 : ptrs->shade + 51;
		ptrs->color = 255 * ptrs->shade * 255;
	}
	if (key == 36)
		ptrs->projectn = ptrs->projectn == 0 ? 1 : 0;
}

int				ft_key(int key, t_struct *ptrs)
{
	char *free_str;
	char *str;

	free_str = NULL;
	str = NULL;
	ft_keys(key, ptrs);
	ptrs->img_ptr = mlx_new_image(ptrs->mlx_ptr, 1000, 1000);
	ptrs->image = mlx_get_data_addr(ptrs->img_ptr,
		&ptrs->img_a, &ptrs->img_b, &ptrs->img_c);
	ptrs->img_a /= 8;
	ft_draw_image(ptrs, ptrs->node_ptr);
	ft_strings(ptrs, free_str, str);
	return (0);
}
