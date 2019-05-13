/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_quicksort_help.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:38:46 by lshanaha          #+#    #+#             */
/*   Updated: 2019/03/08 14:50:16 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_show_usage(void)
{
	write(1, "usage: ./push_swap or ./checker [int_values]\n       You can \
use flag --p to see sorted and unsorted arrs.\n", 106);
	exit(0);
}

void		ft_sort_two(t_stacks *stacks, t_rbroot *root)
{
	if (LEN_A > 1 && (ARR_A[LEN_A - 1] > ARR_A[LEN_A - 2]) &&
		LEN_B > 1 && (ARR_B[LEN_B - 1] < ARR_B[LEN_B - 2]))
		ft_sw_ss(stacks, root);
	else if (LEN_A > 1 && (ARR_A[LEN_A - 1] > ARR_A[LEN_A - 2]))
		ft_sw_a(stacks, root);
	else if (LEN_B > 1 && (ARR_B[LEN_B - 1] < ARR_B[LEN_B - 2]))
		ft_sw_b(stacks, root);
}

void		ft_sort_three_in_a(t_stacks *stacks, t_rbroot *root)
{
	if (ARR_A[0] < ARR_A[1] && ARR_A[1] < ARR_A[2])
	{
		ft_sw_a(stacks, root);
		ft_rev_rot_a(stacks, root);
	}
	else if (ARR_A[0] > ARR_A[1] && ARR_A[1] < ARR_A[2])
		(ARR_A[0] < ARR_A[2]) ? ft_rot_a(stacks, root) : ft_sw_a(stacks, root);
	else if (ARR_A[0] < ARR_A[1] && ARR_A[0] > ARR_A[2])
	{
		ft_rev_rot_a(stacks, root);
		ft_sw_a(stacks, root);
	}
	else if (ARR_A[0] < ARR_A[2] && ARR_A[1] > ARR_A[2])
		ft_rev_rot_a(stacks, root);
}

void		ft_sort_three_in_b(t_stacks *stacks, t_rbroot *root)
{
	if (ARR_B[0] > ARR_B[1] && ARR_B[1] > ARR_B[2])
	{
		ft_sw_b(stacks, root);
		ft_rev_rot_b(stacks, root);
	}
	if (ARR_B[0] > ARR_B[2] && ARR_B[2] > ARR_B[1])
		ft_rev_rot_b(stacks, root);
	if (ARR_B[2] > ARR_B[0] && ARR_B[0] > ARR_B[1])
	{
		ft_rev_rot_b(stacks, root);
		ft_sw_b(stacks, root);
	}
	if (ARR_B[1] > ARR_B[0] && ARR_B[0] > ARR_B[2])
		ft_rot_b(stacks, root);
	if (ARR_B[1] > ARR_B[2] && ARR_B[2] > ARR_B[0])
		ft_sw_b(stacks, root);
}

t_rbroot	*ft_ps_quick(int *a, int len, int flag)
{
	t_stacks	*stacks;
	t_rbroot	*qck;

	qck = ft_root_init();
	stacks = ft_stacks_init(a, len);
	ft_selector_a(stacks, qck, LEN_A);
	while (LEN_B > 0)
		ft_psh_a(stacks, qck);
	if (flag)
		ft_print_stacks(stacks, LEN_A, LEN_B);
	ft_clear_stacks(stacks);
	ft_tree_optimize(qck, 0, 0, -1);
	return (qck);
}
