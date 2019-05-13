/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:17:23 by lshanaha          #+#    #+#             */
/*   Updated: 2019/03/14 13:11:48 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

static void		ft_arrs(int *arr, int i)
{
	while (--i >= 0)
	{
		ft_fprintf(0, "%3d: |%11d|    |%12|\n", i, arr[i]);
	}
	ft_putchar_fd('\n', 0);
}

void			ft_solve_swap(t_stacks *stacks, int i, int flag, int j)
{
	char	*temp;

	while (get_next_line(0, &temp) > 0)
	{
		i = 0;
		(!ft_strcmp(temp, "sa")) ? (ft_swap_a(stacks)) : i++;
		(!ft_strcmp(temp, "sb")) ? (ft_swap_b(stacks)) : i++;
		(!ft_strcmp(temp, "ss")) ? (ft_swap_ss(stacks)) : i++;
		(!ft_strcmp(temp, "pa")) ? (ft_push_a(stacks)) : i++;
		(!ft_strcmp(temp, "pb")) ? (ft_push_b(stacks)) : i++;
		(!ft_strcmp(temp, "ra")) ? (ft_rotate_a(stacks)) : i++;
		(!ft_strcmp(temp, "rb")) ? (ft_rotate_b(stacks)) : i++;
		(!ft_strcmp(temp, "rr")) ? (ft_rotate_both(stacks)) : i++;
		(!ft_strcmp(temp, "rra")) ? (ft_rev_rotate_a(stacks)) : i++;
		(!ft_strcmp(temp, "rrb")) ? (ft_rev_rotate_b(stacks)) : i++;
		(!ft_strcmp(temp, "rrr")) ? (ft_rev_rotate_both(stacks)) : i++;
		free(temp);
		(i != 10) ? exit(ft_show_error()) : j++;
	}
	(j) ? free(temp) : 0;
	(ft_ps_arr_sorted(ARR_A, LEN_A, LEN_B)) ? write(1, "KO\n", 3) :\
	write(1, "OK\n", 3);
	(flag) ? ft_print_stacks(stacks, LEN_A, LEN_B) : 0;
	ft_clear_stacks(stacks);
}

static void		ft_killer_func(int argc, char *str, int i, int flag)
{
	char	**argv;
	int		*a;
	int		res;

	argv = (ft_strsplit(str, ' '));
	while (argv[argc])
		argc++;
	(!(a = (int *)ft_memalloc(argc * 4))) ? exit(ft_show_error()) : (0);
	i = -1;
	while (++i < argc)
	{
		(!(res = ft_check_args(argv[i], 0, 0))) ? exit(ft_show_error()) : 0;
		(res == 1) ? a[i] = ft_atoi(argv[i]) : argc--;
		flag = flag | ((res == 1) ? 0 : res);
	}
	ft_check_repeates(a, 0, 0, argc);
	ft_int_arr_rev(a, argc - 1);
	(flag) ? ft_arrs(a, argc) : 0;
	(i > 1) ? ft_solve_swap(ft_stacks_init(a, argc), 0, flag, 0) : 0;
	while (--argc >= 0)
		free(argv[argc]);
	free(argv);
	free(a);
	exit(0);
}

int				main(int argc, char *argv[])
{
	int			i;
	int			*a;
	int			res;
	int			flag;

	(argc < 2) ? exit(0) : (flag = 0);
	if (argc == 2)
		ft_killer_func(0, argv[1], -1, flag);
	argv = &argv[1];
	argc = argc - 1;
	(!(a = (int *)ft_memalloc(argc * 4))) ? exit(ft_show_error()) : (0);
	i = -1;
	while (++i < argc)
	{
		(!(res = ft_check_args(argv[i], 0, 0))) ? exit(ft_show_error()) : 0;
		(res == 1) ? a[i] = ft_atoi(argv[i]) : argc--;
		flag = flag | ((res == 1) ? 0 : res);
	}
	ft_check_repeates(a, 0, 0, argc);
	ft_int_arr_rev(a, argc - 1);
	(flag) ? ft_arrs(a, argc) : 0;
	ft_solve_swap(ft_stacks_init(a, argc), 0, flag, 0);
	free(a);
	return (0);
}
