/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_funcs1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:11:14 by lshanaha          #+#    #+#             */
/*   Updated: 2019/02/18 16:10:20 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stacks *stacks)
{
	int		temp;

	temp = ARR_A[LEN_A - 1];
	ARR_A[LEN_A - 1] = ARR_A[LEN_A - 2];
	ARR_A[LEN_A - 2] = temp;
}

void	ft_swap_b(t_stacks *stacks)
{
	int		temp;

	temp = ARR_B[LEN_B - 1];
	ARR_B[LEN_B - 1] = ARR_B[LEN_B - 2];
	ARR_B[LEN_B - 2] = temp;
}

void	ft_swap_ss(t_stacks *stacks)
{
	int		temp;

	temp = 0;
	if (LEN_A > 1)
	{
		temp = ARR_A[LEN_A - 1];
		ARR_A[LEN_A - 1] = ARR_A[LEN_A - 2];
		ARR_A[LEN_A - 2] = temp;
	}
	if (LEN_B > 1)
	{
		temp = ARR_B[LEN_B - 1];
		ARR_B[LEN_B - 1] = ARR_B[LEN_B - 2];
		ARR_B[LEN_B - 2] = temp;
	}
}

void	ft_push_a(t_stacks *stacks)
{
	ARR_A[LEN_A] = ARR_B[LEN_B - 1];
	LEN_A++;
	LEN_B--;
}

void	ft_push_b(t_stacks *stacks)
{
	ARR_B[LEN_B] = ARR_A[LEN_A - 1];
	LEN_A--;
	LEN_B++;
}
