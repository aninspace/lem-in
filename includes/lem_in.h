/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoonor <rdonnor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:06:50 by rdonnor           #+#    #+#             */
/*   Updated: 2020/05/31 21:04:21 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <sys/_types/_o_sync.h>
# include <limits.h>

typedef struct		s_map
{
	int				height;
}					t_map;

typedef	struct		s_room
{
	char			*name;
	int				c_x;
	int				c_y;
	int				flag;
	int				len;
	int				index;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	char			*start;
	char			*end;
	struct s_link	*next;
}					t_link;

typedef struct		s_se
{
	char			*start;
	char			*end;
	int				start_c_x;
	int				start_c_y;
	int				end_c_x;
	int				index_s;
	int				end_c_y;
	int				index_e;
}					t_se;

typedef struct		s_amount
{
	int				room;
	int				link;
	int				comment;
	int				s;
	int				e;
	int				ant;
	int				new_link;
	int				way;
	int				step;
	int				cmd;
}					t_amount;

typedef struct		s_ver
{
	int				*ver;
	struct s_ver	*next;
}					t_ver;

typedef struct		s_ant
{
	int				*len_way;
	int				*c_len_way;
	int				**step;
	int				**ant;
	int				a;
	int				k;
	int				r_ant;
	int				i;
	int				an;
	int				j;
	int				p;
}					t_ant;

typedef struct		s_path
{
	int				i;
	int				k;
	int				j;
	int				p;
}					t_path;

typedef	struct		s_lem
{
	int				height;
	t_map			*map;
	t_room			*room;
	t_amount		*am;
	t_link			*link;
	t_se			*se;
	t_ver			*ver;
	t_ant			*ant;
	t_path			*pt;
	char			*found;
	char			*start;
	char			*end;
	int				*d;
	int				*v;
	int				**mat;
	int				*new_ver;
	int				r;
	int				l;
	int				**path;
	int				p;
	int				**mat1;
	char			**remember;
	int				t;
	int				a;
	int				an;
	int				r_ant;
	int				dist;
	int				weight;
	int				fd;
}					t_lem;

t_lem				*init_lem_in(void);
bool				amount_ants(t_lem *lem, char *line);
int					len_arr(char **arr);
bool				read_map(t_lem *lem);
t_amount			*init_amount(void);
t_room				*init_room(void);
bool				is_start(char *line);
bool				is_end(char *line);
bool				is_comment(char *line);
bool				is_room(t_lem *lem, char *line);
bool				is_link(t_lem *lem, char *line, t_room *room);
bool				is_comment(char *line);
bool				is_start(char *line);
bool				is_end(char *line);
bool				match_se(t_lem *lem, t_link *link);
bool				check_link_duplicate(t_link *link);
bool				check_link_reserve_duplicate(t_link *link);
bool				check_dupl_coord(t_lem *lem, t_room *room);
bool				check_name_duplicate(t_lem *lem, t_room *room);
void				change_graph_weight(t_lem *lem);
t_link				*init_link(void);
t_se				*init_se(void);
int					how_many_dashes(char *str);
char				*link_name_with_dashes(t_lem *lem, t_room *room, char *str);
bool				algo_deixtra(t_lem *lem);
char				*find_room_name(t_lem *lem, int index, t_room *room);
void				connect_ways(t_lem *lem, t_ver *ver);
void				null_graph(t_lem *lem);
void				find_way(t_lem *lem, int r);
void				null_one_way(t_lem *lem);
void				recovery_way(t_lem *lem, int *d);
void				count_ways(t_lem *lem, t_ver *ver);
void				init_path(t_lem *lem, int way);
t_ver				*init_ver(void);
void				delete_path(t_lem *lem, int i, int k, t_path *pt);
void				check_paths(t_lem *lem, t_path *pt);
int					**init_new_path(t_lem *lem, int way);
int					int_len(int *k);
int					*int_copy(int *dest, int *src);
void				swap_path_in_asceting_order(t_lem *lem);
void				step_of_ants(t_lem *lem);
t_ant				*init_ant(t_lem *lem);
void				init_step(t_lem *lem);
void				init_ant_in_step(t_lem *lem);
void				init_change_lenght_way(t_lem *lem);
void				init_mat(t_lem *lem);
void				free_mat(t_lem *lem);
void				free_new_path(int **new_path, int way);
void				free_all(t_lem *lem, t_ver *tmp);
void				init_lenght_way(t_lem *lem);
void				free_remember(t_lem *lem);
int					put_ant_in_previous_step(t_lem *lem, int i);
bool				check_ant_in_previous_step(t_lem *lem, int st, int j,
																	int i);
int					check_lenght_path(t_lem *lem, int k);
int					count_previous_step(t_lem *lem, int step);
bool				is_ant_in_step(t_lem *lem, int st, int ant);
void				check_valid(t_lem *lem);
void				free_se(t_lem *lem);
void				free_lem_in(t_lem *lem);
void				free_room(t_lem *lem);
void				free_link(t_lem *lem);
void				init_step_of_ants(t_lem *lem);
bool				is_command(char *line);
int					init_begin(t_lem *lem, t_room *room);
int					init_end(t_lem *lem, t_room *room);
void				print_map(t_lem *lem);
void				init_struct_path(t_lem *lem);
t_lem				*full_init(void);

#endif
