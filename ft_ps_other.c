/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:11:26 by lshanaha          #+#    #+#             */
/*   Updated: 2019/02/18 16:39:36 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void		ft_rot_a(t_stacks *stacks, t_rbroot *root)
{
	if (LEN_A <= 1)
		return ;
	ft_rotate_a(stacks);
	rb_insert(root, (root->count + 1), "ra\n");
}

void		ft_rotate_a(t_stacks *stacks)
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
}

t_stacks	*ft_stacks_init(int *a, int lena)
{
	int			*b;
	int			*temp;
	int			i;
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	temp = (int *)ft_memalloc(4 * lena);
	b = (int *)ft_memalloc(4 * lena);
	if (!b || !stacks || !temp)
		exit(ft_show_error());
	i = -1;
	while (++i < lena)
		temp[i] = a[i];
	ARR_A = temp;
	ARR_B = b;
	LEN_A = lena;
	LEN_B = 0;
	return (stacks);
}

t_rbroot	*ft_root_init(void)
{
	t_rbroot	*new;

	new = malloc(sizeof(struct s_rb_tree));
	if (!new)
		exit(ft_show_error());
	new->root = NULL;
	new->count = 0;
	return (new);
}

void		ft_clear_stacks(t_stacks *stacks)
{
	free(ARR_A);
	free(ARR_B);
	free(stacks);
}
