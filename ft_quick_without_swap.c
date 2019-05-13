/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_without_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:10:31 by lshanaha          #+#    #+#             */
/*   Updated: 2019/03/02 18:32:49 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_selector_no_a(t_stacks *stacks, t_rbroot *root, int len)
{
	if (LEN_A == 3)
		ft_sort_three_in_a(stacks, root);
	else if (len == 2)
		ft_sort_two(stacks, root);
	else if (len > 2)
		ft_partition_no_a(stacks, root, len, 0);
}

void		ft_selector_no_b(t_stacks *stacks, t_rbroot *root, int len)
{
	if (LEN_B == 3)
		ft_sort_three_in_b(stacks, root);
	else if (len == 2)
		ft_sort_two(stacks, root);
	else if (len > 2)
		ft_partition_no_b(stacks, root, len, 0);
}

void		ft_partition_no_a(t_stacks *stacks, t_rbroot *root, int len, int i)
{
	int		start;
	int		j;
	int		pivot;

	start = LEN_A - len;
	pivot = ft_arr_mediana(ARR_A, start, len, 1);
	j = 0;
	while (ft_is_values(ARR_A, LEN_A, pivot, 1))
		if (ARR_A[LEN_A - 1] < pivot && ++i)
			ft_psh_b(stacks, root);
		else if (ARR_A[LEN_A - 1] > pivot && ++j)
			ft_rot_a(stacks, root);
		else if (ARR_A[LEN_A - 1] == pivot && ++i)
		{
			ft_psh_b(stacks, root);
			ft_rot_b(stacks, root);
		}
	ft_rev_rot_b(stacks, root);
	ft_reversal(stacks, root, j, 1);
	ft_selector_no_a(stacks, root, len - i);
	while (ARR_A[LEN_A - 1] != pivot)
		ft_psh_a(stacks, root);
	ft_selector_no_b(stacks, root, i - 1);
}

void		ft_partition_no_b(t_stacks *stacks, t_rbroot *root, int len, int i)
{
	int		start;
	int		j;
	int		pivot;

	start = LEN_B - len;
	pivot = ft_arr_mediana(ARR_B, start, len, 0);
	j = 0;
	while (ft_is_values(ARR_B, LEN_B, pivot, 0))
		if (ARR_B[LEN_B - 1] > pivot && ++i)
			ft_psh_a(stacks, root);
		else if (ARR_B[LEN_B - 1] < pivot && ++j)
			ft_rot_b(stacks, root);
		else
		{
			ft_psh_a(stacks, root);
			ft_rot_a(stacks, root);
		}
	ft_rev_rot_a(stacks, root);
	ft_reversal(stacks, root, j, 0);
	ft_psh_b(stacks, root);
	ft_selector_no_a(stacks, root, i);
	while (ARR_A[LEN_A - 1] != pivot)
		ft_psh_a(stacks, root);
	ft_selector_no_b(stacks, root, len - i - 1);
}

t_rbroot	*ft_ps_quick_no_swap(int *a, int len, int flag)
{
	t_stacks	*stacks;
	t_rbroot	*qck;
	t_rbroot	*no_qck;

	no_qck = ft_root_init();
	stacks = ft_stacks_init(a, len);
	ft_selector_no_a(stacks, no_qck, LEN_A);
	while (LEN_B > 0)
		ft_psh_a(stacks, no_qck);
	ft_clear_stacks(stacks);
	ft_tree_optimize(no_qck, 0, 0, -1);
	qck = ft_ps_quick(a, len, flag);
	if (qck->count < no_qck->count)
	{
		ft_rb_freetree(no_qck->root);
		free(no_qck);
	}
	else
	{
		ft_rb_freetree(qck->root);
		free(qck);
		qck = no_qck;
	}
	return (qck);
}
