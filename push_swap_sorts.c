/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:41:43 by lshanaha          #+#    #+#             */
/*   Updated: 2019/03/02 18:34:27 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void		ft_ps_bubble_sort(t_stacks *stacks, t_rbroot *rt, int i, int len)
{
	int	j;

	while (++i < len && ft_ps_arr_sorted(ARR_A, LEN_A, LEN_B))
	{
		j = i - 1;
		while (++j < len)
			if (LEN_B == 0 || ARR_A[LEN_A - 1] > ARR_B[LEN_B - 1])
				ft_psh_b(stacks, rt);
			else if (ARR_A[LEN_A - 1] < ARR_B[LEN_B - 1])
			{
				ft_psh_b(stacks, rt);
				(LEN_A > 1 && LEN_B > 1 && ARR_A[LEN_A - 1] > ARR_A[LEN_A - 2]\
				&& ARR_B[LEN_B - 1] < ARR_B[LEN_B - 2])\
				? ft_sw_ss(stacks, rt) : ft_sw_b(stacks, rt);
			}
		while (LEN_B > 0)
			ft_psh_a(stacks, rt);
	}
}

void		ft_prev_bubble_sort(t_stacks *stacks, t_rbroot *rt, int i, int len)
{
	int	j;

	while (++i < len && ft_ps_arr_sorted(ARR_A, LEN_A, LEN_B))
	{
		j = i - 1;
		while (++j < len)
		{
			if (LEN_A > 1 && ARR_A[LEN_A - 1] > ARR_A[LEN_A - 2])
				(ft_sw_a(stacks, rt));
			if (LEN_B == 0 || ARR_A[LEN_A - 1] > ARR_B[LEN_B - 1])
				ft_psh_b(stacks, rt);
			else if (ARR_A[LEN_A - 1] < ARR_B[LEN_B - 1])
			{
				ft_psh_b(stacks, rt);
				(LEN_A > 1 && LEN_B > 1 && ARR_A[LEN_A - 1] > ARR_A[LEN_A - 2]\
				&& ARR_B[LEN_B - 1] < ARR_B[LEN_B - 2])\
				? ft_sw_ss(stacks, rt) : ft_sw_b(stacks, rt);
			}
		}
		while (LEN_B > 0)
			ft_psh_a(stacks, rt);
	}
}

void		ft_milkshake_sort(t_stacks *stacks, t_rbroot *rt, int i, int len)
{
	int	j;

	while (++i < len && ft_ps_arr_sorted(ARR_A, LEN_A, LEN_B))
	{
		j = i - 1;
		while (++j < len)
			if (LEN_B == 0 || ARR_A[LEN_A - 1] > ARR_B[LEN_B - 1])
				ft_psh_b(stacks, rt);
			else if (ARR_A[LEN_A - 1] < ARR_B[LEN_B - 1])
			{
				ft_psh_b(stacks, rt);
				(LEN_A > 1 && LEN_B > 1 && ARR_A[LEN_A - 1] > ARR_A[LEN_A - 2]\
				&& ARR_B[LEN_B - 1] < ARR_B[LEN_B - 2])\
				? ft_sw_ss(stacks, rt) : ft_sw_b(stacks, rt);
			}
		while (LEN_B > 0)
		{
			ft_psh_a(stacks, rt);
			if (LEN_A > 1 && ARR_A[LEN_A - 1] > ARR_A[LEN_A - 2] && LEN_B > 1\
			&& ARR_B[LEN_B - 1] < ARR_B[LEN_B - 2])
				ft_sw_ss(stacks, rt);
			else if (LEN_A > 1 && ARR_A[LEN_A - 1] > ARR_A[LEN_A - 2])
				ft_sw_a(stacks, rt);
		}
	}
}

t_rbroot	*ft_start(void (*f)(t_stacks *s, t_rbroot *r, int i, int l),\
int *a, int len)
{
	t_stacks	*stacks;
	t_rbroot	*root;

	root = ft_root_init();
	stacks = ft_stacks_init(a, len);
	(*f)(stacks, root, -1, LEN_A);
	ft_clear_stacks(stacks);
	ft_tree_optimize(root, 0, 0, -1);
	return (root);
}

void		ft_ps_sort(int *a, int len, int flag)
{
	t_rbroot	*bbl;
	t_rbroot	*mlk;
	t_rbroot	*prv;
	t_rbroot	*qck;

	if (!ft_ps_arr_sorted(a, len, 0))
		return ;
	if (len < 50)
	{
		bbl = ft_start(ft_ps_bubble_sort, a, len);
		mlk = ft_start(ft_milkshake_sort, a, len);
		prv = ft_start(ft_prev_bubble_sort, a, len);
		qck = ft_ps_quick_no_swap(a, len, flag);
		bbl = ft_whos_extra(bbl, mlk, prv, qck);
	}
	else
		bbl = ft_ps_quick(a, len, flag);
	ft_rbtree_print(bbl->root);
	ft_rb_freetree(bbl->root);
	free(bbl);
}
