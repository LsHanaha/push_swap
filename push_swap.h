/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:53:25 by lshanaha          #+#    #+#             */
/*   Updated: 2019/03/08 14:03:25 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct		s_size {
	int				*a;
	int				*b;
	int				len_a;
	int				len_b;
}					t_stacks;

typedef struct		s_st_end
{
	int				start;
	int				end;
}					t_st_end;

# define ARR_A (stacks->a)
# define ARR_B (stacks->b)
# define LEN_A (stacks->len_a)
# define LEN_B (stacks->len_b)

void				ft_swap_a(t_stacks *stacks);
void				ft_swap_b(t_stacks *stacks);
void				ft_swap_ss(t_stacks *stacks);
void				ft_push_a(t_stacks *stacks);
void				ft_push_b(t_stacks *stacks);
void				ft_rotate_a(t_stacks *stacks);
void				ft_rotate_b(t_stacks *stacks);
void				ft_rotate_both(t_stacks *stacks);
void				ft_rev_rotate_a(t_stacks *stacks);
void				ft_rev_rotate_b(t_stacks *stacks);
void				ft_rev_rotate_both(t_stacks *stacks);

void				ft_sw_a(t_stacks *stacks, t_rbroot *root);
void				ft_sw_b(t_stacks *stacks, t_rbroot *root);
void				ft_sw_ss(t_stacks *stacks, t_rbroot *root);
void				ft_psh_a(t_stacks *stacks, t_rbroot *root);
void				ft_psh_b(t_stacks *stacks, t_rbroot *root);
void				ft_rot_a(t_stacks *stacks, t_rbroot *root);
void				ft_rot_b(t_stacks *stacks, t_rbroot *root);
void				ft_rot_both(t_stacks *stacks, t_rbroot *root);
void				ft_rev_rot_a(t_stacks *stacks, t_rbroot *root);
void				ft_rev_rot_b(t_stacks *stacks, t_rbroot *root);
void				ft_rev_rot_both(t_stacks *stacks, t_rbroot *root);

int					ft_ps_arr_sorted(int *arr, int len, int len_b);
int					ft_rbtree_to_arr(t_rbnode *node, char **arr, int i);
void				ft_arr_optimizer(char **arr, int i, int len, t_rbroot *r);
int					ft_show_error(void);
int					ft_check_args(char *arr, int i, long long temp);
t_stacks			*ft_init_sizes(int argc, int *a, int *b);
void				ft_check_repeates(int *arr, int i, int j, int len);
void				ft_rbtree_colorer(t_rbnode *node);
void				ft_milkshake_sort(t_stacks *stacks, t_rbroot *rt, int i,\
int len);
void				ft_ps_bubble_sort(t_stacks *stacks, t_rbroot *rt, int i,\
int len);
void				ft_ps_sort(int *a, int len, int flag);
t_rbroot			*ft_root_init(void);
t_stacks			*ft_stacks_init(int *a, int lena);
void				ft_tree_optimize(t_rbroot *root, t_rbnode *f, t_rbnode *s,\
int i);
void				ft_clear_stacks(t_stacks *stacks);
t_rbroot			*ft_ps_quick(int *a, int len, int flag);
void				ft_partition_a(t_stacks *stacks, t_rbroot *root, int len,\
int i);
void				ft_partition_b(t_stacks *stacks, t_rbroot *root, int len,\
int i);
void				ft_print_stacks(t_stacks *stacks, int i, int j);
void				ft_sort_two(t_stacks *stacks, t_rbroot *root);
void				ft_sort_three_in_a(t_stacks *stacks, t_rbroot *root);
void				ft_sort_three_in_b(t_stacks *stacks, t_rbroot *root);
void				ft_selector_a(t_stacks *stacks, t_rbroot *root, int len);
void				ft_selector_b(t_stacks *stacks, t_rbroot *root, int len);
int					ft_is_values(int *arr, int len, int val, int flag);

t_rbroot			*ft_whos_extra(t_rbroot *a, t_rbroot *b, t_rbroot *c,\
t_rbroot *d);
void				ft_worker(t_rbroot *root, int data1, int data2, int *i);
void				ft_reversal(t_stacks *stacks, t_rbroot *root, int num,\
int flag);
t_rbroot			*ft_ps_quick_no_swap(int *a, int len, int flag);
void				ft_partition_no_a(t_stacks *stacks, t_rbroot *root,\
int len, int i);
void				ft_partition_no_b(t_stacks *stacks, t_rbroot *root,\
int len, int i);
void				ft_show_usage(void);
int					ft_check_sort(t_stacks *stacks, int len, int flag);

#endif
