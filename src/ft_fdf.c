/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:28:58 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/10 15:31:58 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		ft_read_file(int *fd, t_struct *ptrs, t_node *node,
																int rows)
{
	int		columns;
	char	**str;
	char	*line;

	while (get_next_line(*fd, &line) && ++rows)
	{
		columns = 0;
		str = ft_strsplit(line, ' ');
		free(line);
		while (str[columns])
		{
			node->x = columns;
			node->y = rows;
			node->z = ft_atoi(str[columns]);
			node->next = ft_node_init();
			node = node->next;
			free(str[columns]);
			columns++;
		}
		free(str);
	}
	free(line);
	ptrs->map_length = columns;
	ptrs->map_width = rows;
	ptrs->zoom = ptrs->map_length * 3;
}

void			ft_draw_image(t_struct *ptrs, t_node *node)
{
	if (ptrs->projectn == 0)
		ft_paralel_projection(ptrs, node);
	else
		ft_perspective_projection(ptrs, node);
	ft_draw_lines(ptrs, node);
	mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, ptrs->img_ptr, 0, 0);
	mlx_destroy_image(ptrs->mlx_ptr, ptrs->img_ptr);
}

static void		ft_init_strings(t_struct *ptrs)
{
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 50, 50,
		0xffffff, "rotate with: Arrows");
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 50, 75,
		0xffffff, "move with: W A S D");
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 50, 100,
		0xffffff, "zoom with: + -");
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 50, 125,
		0xffffff, "change color with: Space");
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 50, 150,
		0xffffff, "change projection with: Enter");
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 50, 175,
		0xffffff, "to quit: ESC");
}

static int		ft_init_graphics(int *fd, t_struct *ptrs,
											t_node *node, char **argv)
{
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
	{
		ft_putstr("file not found/not valid\n");
		return (1);
	}
	node = ft_node_init();
	ft_ptrs_init(ptrs);
	ptrs->img_a /= 8;
	ptrs->node_ptr = node;
	ft_read_file(fd, ptrs, node, 0);
	ft_draw_image(ptrs, node);
	ft_init_strings(ptrs);
	mlx_hook(ptrs->win_ptr, 2, 5, ft_key, ptrs);
	mlx_hook(ptrs->win_ptr, 17, 1L << 17, ft_mouse_close, ptrs);
	mlx_loop(ptrs->mlx_ptr);
	if (close(*fd) == -1)
		return (1);
	return (0);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_node		*node;
	t_struct	*ptrs;

	node = NULL;
	if (!(ptrs = (t_struct *)malloc(sizeof(t_struct))))
	{
		free(ptrs);
		return (1);
	}
	if (argc == 2)
		return (ft_init_graphics(&fd, ptrs, node, argv));
	else
		ft_putstr("file not found/not valid\n");
	return (0);
}
