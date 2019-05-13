/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:10:52 by lshanaha          #+#    #+#             */
/*   Updated: 2019/02/28 18:38:12 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_b(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = LEN_B - 1;
	temp = ARR_B[i];
	while (i > 0)
	{
		ARR_B[i] = ARR_B[i - 1];
		i--;
	}
	ARR_B[0] = temp;
}

void	ft_rotate_both(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = LEN_A - 1;
	temp = ARR_A[i];
	while (i > 0)
	{
		ARR_A[i] = ARR_A[i - 1];
		i--;
	}
	ARR_A[0] = temp;
	i = LEN_B - 1;
	temp = ARR_B[i];
	while (i > 0)
	{
		ARR_B[i] = ARR_B[i - 1];
		i--;
	}
	ARR_B[0] = temp;
}

void	ft_rev_rotate_a(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	temp = ARR_A[0];
	while (i < LEN_A)
	{
		ARR_A[i] = ARR_A[i + 1];
		i++;
	}
	ARR_A[LEN_A - 1] = temp;
}

void	ft_rev_rotate_b(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	temp = ARR_B[0];
	while (i < LEN_B)
	{
		ARR_B[i] = ARR_B[i + 1];
		i++;
	}
	ARR_B[LEN_B - 1] = temp;
}

void	ft_rev_rotate_both(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	temp = ARR_A[0];
	while (i < LEN_A)
	{
		ARR_A[i] = ARR_A[i + 1];
		i++;
	}
	ARR_A[LEN_A - 1] = temp;
	i = 0;
	temp = ARR_B[0];
	while (i < LEN_B)
	{
		ARR_B[i] = ARR_B[i + 1];
		i++;
	}
	ARR_B[LEN_B - 1] = temp;
}
