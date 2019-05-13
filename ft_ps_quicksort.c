/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:41:59 by lshanaha          #+#    #+#             */
/*   Updated: 2019/03/08 14:55:03 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_selector_a(t_stacks *stacks, t_rbroot *root, int len)
{
	if (LEN_A == 3)
		ft_sort_three_in_a(stacks, root);
	else if (ft_check_sort(stacks, len, 1))
		return ;
	else if (len == 2)
		ft_sort_two(stacks, root);
	else if (len > 2)
		ft_partition_a(stacks, root, len, 0);
}

void		ft_selector_b(t_stacks *stacks, t_rbroot *root, int len)
{
	if (LEN_B == 3)
		ft_sort_three_in_b(stacks, root);
	else if (ft_check_sort(stacks, len, 0))
		return ;
	else if (len == 2)
		ft_sort_two(stacks, root);
	else if (len > 2)
		ft_partition_b(stacks, root, len, 0);
}

void		ft_partition_a(t_stacks *stacks, t_rbroot *root, int len, int i)
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
	ft_sort_two(stacks, root);
	ft_rev_rot_b(stacks, root);
	ft_reversal(stacks, root, j, 1);
	ft_selector_a(stacks, root, len - i);
	while (ARR_A[LEN_A - 1] != pivot)
		ft_psh_a(stacks, root);
	ft_selector_b(stacks, root, i - 1);
}

void		ft_partition_b(t_stacks *stacks, t_rbroot *root, int len, int i)
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
	ft_sort_two(stacks, root);
	ft_rev_rot_a(stacks, root);
	ft_reversal(stacks, root, j, 0);
	ft_psh_b(stacks, root);
	ft_selector_a(stacks, root, i);
	while (ARR_A[LEN_A - 1] != pivot)
		ft_psh_a(stacks, root);
	ft_selector_b(stacks, root, len - i - 1);
}
