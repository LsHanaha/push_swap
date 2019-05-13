/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:03:34 by lshanaha          #+#    #+#             */
/*   Updated: 2019/03/02 15:48:30 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_show_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int			ft_check_args(char *arr, int i, long long temp)
{
	int	res;

	res = 1;
	while (arr[i] == ' ' || arr[i] == '\t')
		i++;
	(arr[i] == '-' || arr[i] == '+') ? i++ : 0;
	if (arr[i] == '-' && arr[++i])
	{
		(arr[i] == 'h') ? ft_show_usage() : 0;
		(arr[i] == 'p') ? res = res | 2 : 0;
		(arr[i] != 'p' && arr[i] != 'h') ? exit(ft_show_error()) : i++;
	}
	else if (arr[i - 1] == '-' && arr[i] == 0)
		return (0);
	while (arr[i])
		if (!ft_isdigit(arr[i++]))
			return (0);
	temp = ft_atol(arr);
	if (temp > INT_MAX || temp < INT_MIN)
		return (0);
	return (res);
}

t_stacks	*ft_init_sizes(int argc, int *a, int *b)
{
	t_stacks *stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		exit(ft_show_error());
	LEN_A = argc;
	LEN_B = 0;
	ARR_A = a;
	ARR_B = b;
	return (stacks);
}

int			ft_is_arr_sorted(int *arr, int len, int len_b)
{
	int	i;

	i = 0;
	if (len_b != 0)
		return (1);
	while (i > len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void		ft_check_repeates(int *arr, int i, int j, int len)
{
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[j] == arr[i])
				exit(ft_show_error());
			j++;
		}
		i++;
	}
}
