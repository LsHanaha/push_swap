/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_helpers3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:48:05 by lshanaha          #+#    #+#             */
/*   Updated: 2019/03/02 16:05:47 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_ps_arr_sorted(int *arr, int len, int len_b)
{
	int	i;

	i = 0;
	if (len_b != 0)
		return (1);
	while (i < len - 1)
	{
		if (arr[i] < arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

t_rbroot	*ft_whos_extra(t_rbroot *a, t_rbroot *b, t_rbroot *c,\
t_rbroot *d)
{
	t_rbroot	*min1;
	t_rbroot	*min2;
	t_rbroot	*res;

	min1 = (a->count < b->count) ? a : b;
	ft_rb_freetree((a->count < b->count) ? b->root : a->root);
	free((a->count < b->count) ? b : a);
	min2 = (c->count < d->count) ? c : d;
	ft_rb_freetree((c->count < d->count) ? d->root : c->root);
	free((c->count < d->count) ? d : c);
	res = (min1->count < min2->count) ? min1 : min2;
	ft_rb_freetree((min1->count < min2->count) ? min2->root : min1->root);
	free((min1->count < min2->count) ? min2 : min1);
	return (res);
}

void		ft_print_stacks(t_stacks *stacks, int i, int j)
{
	if (i >= j)
	{
		while (--i >= j)
			ft_fprintf(2, "%3d: |%11d|    |%12|\n", i, ARR_A[i]);
		while (--j >= 0)
			ft_fprintf(2, "%3d: |%11d|    |%11d|\n", j, ARR_A[j], ARR_B[j]);
	}
	else
	{
		while (--j >= i)
			ft_fprintf(2, "%3d: |%12|    |%11d|\n", j, ARR_B[j]);
		while (--i >= 0)
			ft_fprintf(2, "%3d: |%11d|    |%11d|\n", i, ARR_A[i], ARR_B[i]);
	}
	ft_putchar_fd('\n', 2);
}

void		ft_worker(t_rbroot *root, int data1, int data2, int *i)
{
	ft_rbtree_del(root, data1);
	ft_rbtree_del(root, data2);
	*i = ft_rbtree_min(root->root) - 1;
}

void		ft_reversal(t_stacks *stacks, t_rbroot *root, int num, int flag)
{
	if (flag)
	{
		if (num != LEN_A)
			while (num-- != 0)
				ft_rev_rot_a(stacks, root);
	}
	else
	{
		if (num != LEN_B)
			while (num-- != 0)
				ft_rev_rot_b(stacks, root);
	}
}
