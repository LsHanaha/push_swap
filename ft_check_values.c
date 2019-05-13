/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:12:29 by lshanaha          #+#    #+#             */
/*   Updated: 2019/03/08 14:34:45 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_is_values(int *arr, int len, int val, int flag)
{
	int	i;

	i = 0;
	if (flag)
		while (i < len)
		{
			if (arr[i] <= val)
				return (1);
			i++;
		}
	else
		while (i < len)
		{
			if (arr[i] >= val)
				return (1);
			i++;
		}
	return (0);
}

int			ft_check_sort(t_stacks *stacks, int len, int flag)
{
	int	i;

	if (len < 2)
		return (1);
	if (flag)
	{
		i = LEN_A - len;
		while (i < LEN_A - 1)
		{
			if (ARR_A[i] < ARR_A[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		i = LEN_B - len;
		while (i < LEN_B - 1)
		{
			if (ARR_B[i] > ARR_B[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}
