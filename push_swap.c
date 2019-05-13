/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:12:19 by lshanaha          #+#    #+#             */
/*   Updated: 2019/03/08 14:17:30 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

static void		ft_arrs(int *arr, int i)
{
	while (--i >= 0)
		ft_fprintf(0, "%3d: |%11d|    |%12|\n", i, arr[i]);
	ft_putchar_fd('\n', 0);
}

void			ft_go_ps_sort(int *a, int len, int flag)
{
	if (flag)
		ft_arrs(a, len);
	if (len == 2)
		(a[0] < a[1]) ? write(1, "sa\n", 3) : 0;
	else if (len == 3)
	{
		if (a[0] < a[1] && a[1] < a[2])
			write(1, "sa\nrra\n", 7);
		else if (a[0] > a[1] && a[1] < a[2])
			(a[0] < a[2]) ? write(1, "ra\n", 3) : write(1, "sa\n", 3);
		else if (a[0] < a[1] && a[0] > a[2])
			write(1, "rra\nsa\n", 7);
		else if (a[0] < a[2] && a[1] > a[2])
			write(1, "rra\n", 4);
	}
	else
		ft_ps_sort(a, len, flag);
}

static void		ft_killer_func(int argc, char *str, int i, int flag)
{
	char	**argv;
	int		res;
	int		*a;

	argv = ft_strsplit(str, ' ');
	while (argv[argc])
		argc++;
	(!(a = (int *)ft_memalloc(argc * 4))) ? exit(ft_show_error()) : (0);
	i = -1;
	while (++i < argc)
	{
		(!(res = (ft_check_args(argv[i], 0, 0)))) ? exit(ft_show_error()) : 0;
		(res == 1) ? a[i] = ft_atoi(argv[i]) : argc--;
		flag = flag | res;
	}
	ft_check_repeates(a, 0, 0, argc);
	ft_int_arr_rev(a, argc - 1);
	(i > 1) ? ft_go_ps_sort(a, argc, flag - 1) : 0;
	while (--argc >= 0)
		free(argv[argc]);
	free(argv);
	free(a);
	exit(0);
}

int				main(int argc, char **argv)
{
	int		i;
	int		*a;
	int		flag;
	int		res;

	(argc < 2) ? exit(0) : (flag = 0);
	if (argc == 2)
		ft_killer_func(0, argv[1], -1, flag);
	argv = &argv[1];
	argc = argc - 1;
	(!(a = (int *)ft_memalloc(argc * 4))) ? exit(ft_show_error()) : (0);
	i = -1;
	while (++i < argc)
	{
		(!(res = (ft_check_args(argv[i], 0, 0)))) ? exit(ft_show_error()) : 0;
		(res == 1) ? a[i] = ft_atoi(argv[i]) : argc--;
		flag = flag | res;
	}
	ft_check_repeates(a, 0, 0, argc);
	ft_int_arr_rev(a, argc - 1);
	(i > 1) ? ft_go_ps_sort(a, argc, flag - 1) : 0;
	free(a);
	return (0);
}
