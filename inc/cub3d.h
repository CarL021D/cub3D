/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imessaad <imessaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:56:19 by caboudar          #+#    #+#             */
/*   Updated: 2023/09/02 23:53:34 by imessaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "../srcs/parsing/get_next_line/get_next_line.h"

# define SCREEN_HEIGHT 480
# define SCREEN_WIDTH 640
# define TEXT_HEIGHT 64
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define ROTATE_LEFT_KEY 65361
# define ROTATE_RIGHT_KEY 65363
# define ROT_SPEED 0.05

typedef struct s_tex
{
	void	*img;
	int		*addr;
	char	*path;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_tex;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_tex		tex[4];
	char		**map;
	int			map_width;
	int			map_height;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			pix_color[SCREEN_HEIGHT][SCREEN_WIDTH];
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	int			c_color;
	int			f_color;
	char		*ceiling_color;
	char		*floor_color;
	int			ceiling_r;
	int			ceiling_g;
	int			ceiling_b;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			nb_data;
	char		*map_simple;
	int			*texture[4];
	void		*img;
	int			*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			current_buffer;
}	t_data;	

typedef struct s_rayc
{
	double		camera_x;
	int			hit;
	int			side;
	int			line_height;
	double		perp_wall_dist;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			tex_num;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	double		raydir_x;
	double		raydir_y;
	int			draw_start;
	int			draw_end;

}	t_rayc;

//			PARSING
void		fusion_colors(t_data *ptr);
void		fusion_colors_f(t_data *ptr);
size_t		ft_strlen(const char *str);
t_data		*create_and_set(int fd);
size_t		ft_strlen(const char *str);
long int	ft_atoi(const char *nptr);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t n);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);
char		*ft_skip_space(char *str);
char		*ft_join_map(char *map, char *line);
char		*skip_all_spaces(char *str);
char		*skip_all_spaces(char *str);
int			ft_isdigit(int c);
int			ft_check_valid_data(t_data *ptr);
int			ft_is_white_space(char c);
int			open_and_check(char **av);
int			check_lines(t_data *ptr, char *str);
int			check_space(char *str);
int			check_extension_xpm(char *str);
int			check_files(char *str);
int			check_virg(char *str);
int			pars_colors(char *str, t_data *ptr, char c);
int			ft_check_space(char *str);
int			ft_check_colors(char *str, t_data *ptr, char c);
int			ft_check_characters_map(char **map);
int			ft_check_empty_line_map(char **map);
int			ft_check_items_map(char **map, char c);
int			ft_check_map(char **map);
int			non_wall(char c);
int			ft_check_walls(char **map);
int			ft_create_and_set_norm(t_data *ptr, char *after_space, char *line);
void		ft_free_split(char **split);
void		*ft_calloc(size_t nmenb, size_t size);
void		set_struct_values(t_data *ptr);
void		assign_colors(int val, t_data *ptr, char c);
void		recreate_map(char **map);
void		ft_delete_empty(char **map);
void		ft_free_(t_data *ptr);

//			RENDERING
void		game_init(t_data *data);
void		player_pos_init(t_data *data);
void		draw_rays(t_data *data, t_rayc *rayc, int x);
void		get_wall_x(t_data *data, t_rayc *rayc);	
void		get_text_x(t_rayc *rayc);
void		ray_dist_init(t_rayc *rayc);	
void		dda(t_data *data, t_rayc *rayc);
void		init_step_and_side_dist(t_data *data, t_rayc *rayc);
void		member_init(t_data *data, t_rayc *rayc, int x);
bool		move_forward(t_data *data, int keycode);
bool		move_backward(t_data *data, int keycode);
bool		move_left(t_data *data, int keycode);
bool		move_right(t_data *data, int keycode);
bool		rotate_left(t_data *data, int keycode);
bool		rotate_right(t_data *data, int keycode);
int			draw_on_screen(t_data *data);
int			keys_handler(int key, t_data *data);
int			free_and_exit(t_data *data);

#endif