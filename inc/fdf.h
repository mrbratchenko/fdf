/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:08:16 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/10 15:24:11 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "mlx.h"
# include "../libft/inc/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

int					get_next_line(const int fd, char **line);

typedef struct		s_node
{
	double			x;
	double			y;
	double			z;
	double			temp_x;
	double			temp_y;
	double			temp_z;
	int				i;
	double			centr_x;
	double			centr_y;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	struct s_node	*next;

}					t_node;

typedef struct		s_struct
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*image;
	int				img_a;
	int				img_b;
	int				img_c;
	int				map_length;
	int				map_width;
	double			win_height;
	t_node			*node_ptr;
	double			x_angle;
	double			y_angle;
	double			z_angle;
	int				zoom;
	int				color_ptr;
	int				moved_x;
	int				moved_y;
	size_t			color;
	size_t			shade;
	int				projectn;
	int				elevat;
}					t_struct;

t_node				*ft_node_init();
void				ft_ptrs_init(t_struct *ptrs);
int					ft_key(int key, t_struct *ptrs);
void				ft_pixel_put(t_struct *ptrs, int x, int y);
void				ft_line(int flag, t_node *node,
									t_node *current, t_struct *ptrs);
void				ft_draw_lines(t_struct *ptrs, t_node *node);
void				ft_axis_rotation(t_struct *ptrs, t_node *node);
void				ft_paralel_projection(t_struct *ptrs, t_node *node);
void				ft_perspective_projection(t_struct *ptrs, t_node *node);
void				ft_draw_image(t_struct *ptrs, t_node *node);
int					ft_mouse_close(void);
int					main(int argc, char **argv);

#endif
