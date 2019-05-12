/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 17:11:52 by zwang             #+#    #+#             */
/*   Updated: 2018/10/01 15:35:18 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "libft.h"
# include "time.h"

typedef struct			s_box
{
	int					num;
	t_bool				is_empty;
	struct s_box		*prev;
	struct s_box		*next;
}						t_box;

typedef	struct			s_box_stacks
{
	t_box				*a;
	t_box				*b;
	size_t				len;
}						t_box_stacks;

typedef struct			s_command
{
	char				*cmd_code;
	struct s_command	*prev;
	struct s_command	*next;
}						t_command;

typedef struct			s_options
{
	t_bool				v_option;
	t_bool				n_option;
	t_bool				d_option;
	t_bool				o_option;
	int					arg_index;
	int					flag;
}						t_options;

typedef struct			s_room
{
	t_box_stacks		*box_stacks;
	t_command			*cmd_queue;
	t_options			*options;
	char				**argv;
	int					argc;
	int					program_index;
}						t_room;

/*
** STAGE
*/

t_box_stacks			*create_box_stacks(int *int_list, size_t len);

t_command				*create_command(char *cmd_code);
void					append_command(t_command **cmd_queue,
										t_command *new_cmd);
int						create_command_queue(t_command **cmd_queue);

/*
** ASSISTANT
*/

# define MATCH(x, y) ft_strcmp(x, y) == 0

# define SEP "------------------------------------------"

t_bool					is_sorted(t_box_stacks *box_stacks);
t_bool					duplicates_exist(int *int_list, size_t len);
t_bool					is_ss(t_command *cmd);
t_bool					is_rr(t_command *cmd);
t_bool					is_rrr(t_command *cmd);

void					print_status(t_box_stacks *box_stacks);
t_command				*print_init_or_cmd(t_box_stacks *box_stacks,
											t_command *cmd,
											t_options *option,
											t_bool is_init);

void					collect_options(int argc, char **argv,
										t_options *options);
void					perform_with_pictures(t_box_stacks *box_stacks,
											t_command *cmd_queue,
											t_options *options);
size_t					count_cmd_num(t_command *cmd_queue);

t_box					*get_end_box(t_box *box_stack, t_bool is_upper_end);
size_t					count_box_amount(t_box *stack);
size_t					find_top_sorted_part(t_box *box_stack, char order);
size_t					find_bottom_sorted_part(t_box *box_stack, char order);
size_t					count_sorted_part(t_box_stacks *box_stacks,
											char stack_code);

t_options				*check_options(int argc, char **argv);
int						check_input(t_room *room, size_t len, char **num_list);
int						prepare_behind_curtain(t_room *room);

int						get_min_num(t_box *box_stack);
size_t					get_distance_to_end(t_box *box_stack, int num,
											t_bool is_upper_end);

/*
** ACTOR
*/

void					swap(t_box_stacks *box_stacks, char stack);
void					swap_both(t_box_stacks *box_stacks);

void					push(t_box_stacks *box_stacks, char dst_stack);

void					rotate(t_box_stacks *box_stacks, char stack);
void					rotate_both(t_box_stacks *box_stacks);

void					reverse_rotate(t_box_stacks *box_stacks, char stack);
void					reverse_rotate_both(t_box_stacks *box_stacks);

void					act(t_box_stacks *box_stacks, t_command **cmd_queue,
							char *cmd_code);

/*
** DIRECTOR
*/

void					basic_match_call(t_box_stacks *box_stacks,
											char *cmd_code);
void					execute_actions(t_box_stacks *box_stacks,
										t_command *cmd_queue,
										t_options *options);

t_command				*simple_sort(t_box_stacks *box_stacks,
										size_t box_amount);
t_command				*selection_sort(t_box_stacks *box_stacks);
t_command				*merge_sort(t_box_stacks *box_stacks);
t_command				*design_actions(t_box_stacks *box_stacks);

#endif
