/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_stack_ins2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:12:01 by lshanaha          #+#    #+#             */
/*   Updated: 2019/02/18 15:17:38 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sw_a(t_stacks *stacks, t_rbroot *root)
{
	if (LEN_A <= 1)
		return ;
	ft_swap_a(stacks);
	rb_insert(root, (root->count + 1), "sa\n");
}

void	ft_sw_b(t_stacks *stacks, t_rbroot *root)
{
	if (LEN_B <= 1)
		return ;
	ft_swap_b(stacks);
	rb_insert(root, (root->count + 1), "sb\n");
}

void	ft_sw_ss(t_stacks *stacks, t_rbroot *root)
{
	if (LEN_A <= 1 && LEN_B <= 1)
		return ;
	ft_swap_ss(stacks);
	rb_insert(root, (root->count + 1), "ss\n");
}

void	ft_psh_a(t_stacks *stacks, t_rbroot *root)
{
	if (LEN_B == 0)
		return ;
	ft_push_a(stacks);
	rb_insert(root, (root->count + 1), "pa\n");
}

void	ft_psh_b(t_stacks *stacks, t_rbroot *root)
{
	if (LEN_A == 0)
		return ;
	ft_push_b(stacks);
	rb_insert(root, (root->count + 1), "pb\n");
}
