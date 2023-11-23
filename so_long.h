/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:35:20 by tobeshouta        #+#    #+#             */
/*   Updated: 2023/11/23 17:38:34 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"

# define TRUE 1
# define FALSE 0
# define MALLOC_ERROR 1
# define MAP_TITLE "so_long"
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17
# define MAP_PLAYER_COLLECTION 'C'
# define MAP_ENEMY 'X'
# define MAP_TRAP 'T'
# define MAP_EXIT 'E'
# define MAP_LAND '0'
# define MAP_PLAYER 'P'
# define MAP_WALL '1'
# define MAP_RIVAL 'R'
# define MAP_RIVAL_COLLECTION 'L'

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*map_line;
	int		map_height;
	int		map_width;
	void	*img_land;
	void	*img_wall;
	void	*img_player;
	void	*img_player_colleciton;
	void	*img_exit;
	void	*img_enemy;
	void	*img_trap;
	void	*img_rival;
	void	*img_rival_collection;
	void	*img_zero;
	void	*img_one;
	void	*img_two;
	void	*img_three;
	void	*img_four;
	void	*img_five;
	void	*img_six;
	void	*img_seven;
	void	*img_eight;
	void	*img_nine;
	void	*img_player_icon;
	void	*img_rival_icon;
	int		img_width;
	int		img_height;
	int		player_collection_count;
	int		total_player_collection_count;
	int		rival_collection_count;
	int		total_rival_collection_count;
	int		total_enemy_count;
	int		player_number_of_movements;
	int		rival_number_of_movements;
	int		seed;
	char	*map_line_for_test;
	int		is_able_to_exit;
	int		collection_count_for_test;
	int		player_resporn_nth_pos;
	int		rival_resporn_nth_pos;
	int		*enemy_pos;
	int		key_esc;
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_up_arrow;
	int		key_right_arrow;
	int		key_down_arrow;
	int		key_left_arrow;
	int		key_i;
	int		key_j;
	int		key_k;
	int		key_l;
	int		is_bonus;
}			t_data;

void		swap(int *n1, int *n2);
int			count(char *str, char c);
size_t		ft_strlen_without_newline(const char *str);
char		*ft_strdup_without_newline(const char *src);
char		*ft_strjoin_without_newline(char const *s1, char const *s2);
void		init_key_code(t_data *data);
void		init_data(t_data *data);
void		init_game(t_data *data);
void		get_map_data(char *file_path, t_data *data);
void		get_total_collection_count(t_data *data);
void		get_map_line_and_width_and_height(char *file_path, t_data *data);
int			get_current_nth_pos(char *map_line, char map_target);
void		get_enemy_data(t_data *data);
void		check_map(t_data *data);
void		check_is_map_rectangle(t_data *data);
void		check_map_element(t_data *data);
void		check_is_map_able_to_be_finished(t_data *data);
void		depth_first_search(t_data *data, int current_nth_pos,
				int total_collection_count, char map_collection);
void		check_player_only_one(t_data *data);
void		check_rival_only_one(t_data *data);
void		check_exit_only_one(t_data *data);
void		check_player_collection_at_least_one(t_data *data);
void		check_rival_collection_at_least_one(t_data *data);
void		check_is_wall_surrounded(t_data *data);
void		check_is_each_wall_surrounded(t_data *data, int starting_pos_nth,
				int end_pos_nth, int distance_to_next_pos_nth);
void		check_is_able_to_gain_all_collections_and_exit(t_data *data,
				int total_collection_count, char *target);
void		check_can_player_finish(t_data *data);
void		check_can_rival_finish(t_data *data);
void		check_map_components(t_data *data);
void		check_map_components_bonus(t_data *data);
void		check_map_components_mandantory(t_data *data);
void		check_arg(int argc, char **argv);
void		check_file_path(int fd);
void		put_error_msg(char *error_msg);
void		mlx_all_xpm_file_to_image(t_data *data);
void		mlx_destroy_image_all(t_data *data);
void		create_map(t_data *data);
void		update_game(t_data *data);
int			proc_key_press(int key_code, t_data *data);
void		proc_player_move(int key_code, t_data *data);
void		proc_rival_move(int key_code, t_data *data);
int			finish_game(t_data *data);
void		move_player_next_pos(t_data *data, int next_nth_pos);
void		move_rival_next_pos(t_data *data, int next_nth_pos);
void		crash_player(t_data *data);
void		crash_rival(t_data *data);
void		proc_colliding_with_enemy(t_data *data, char map_target,
				int resporn_nth_pos, char map_opponent);
void		proc_there_is_opponent_in_next_pos(t_data *data, char map_target,
				int next_nth_pos);
void		swap_player_key_code_type_1(t_data *data);
void		swap_player_key_code_type_2(t_data *data);
void		swap_player_key_code_type_3(t_data *data);
void		swap_key_code_by_player_number_of_movements(t_data *data);
void		swap_rival_key_code_type_1(t_data *data);
void		swap_rival_key_code_type_2(t_data *data);
void		swap_rival_key_code_type_3(t_data *data);
void		swap_key_code_by_rival_number_of_movements(t_data *data);
void		swap_current_pos_and_next_pos(t_data *data, char moving_target,
				int next_nth_pos, char current_pos_img_after_movement);
int			is_malloc_error(void *ptr);
int			is_next_pos_goal_for_player(char next_pos, t_data *data);
int			is_next_pos_goal_for_rival(char next_pos, t_data *data);
int			is_able_to_move(char next_pos);
int			is_pvp(t_data *data);
int			lcg_rand(t_data *data);
void		proc_enemy_move(t_data *data);
int			is_key_input(int key_code, t_data *data);
void		mlx_xpm_num_file_to_image(t_data *data);
void		mlx_put_each_of_num_image_to_window(t_data *data, int w, int h,
				int number_of_movements);
#endif
