/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_stack_ins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:11:53 by lshanaha          #+#    #+#             */
/*   Updated: 2019/02/18 15:17:35 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot_b(t_stacks *stacks, t_rbroot *root)
{
	if (LEN_B <= 1)
		return ;
	ft_rotate_b(stacks);
	rb_insert(root, (root->count + 1), "rb\n");
}

void	ft_rot_both(t_stacks *stacks, t_rbroot *root)
{
	if (LEN_A <= 1 && LEN_B <= 1)
		return ;
	ft_rotate_both(stacks);
	rb_insert(root, (root->count + 1), "rr\n");
}

void	ft_rev_rot_a(t_stacks *stacks, t_rbroot *root)
{
	if (LEN_A <= 1)
		return ;
	ft_rev_rotate_a(stacks);
	rb_insert(root, (root->count + 1), "rra\n");
}

void	ft_rev_rot_b(t_stacks *stacks, t_rbroot *root)
{
	if (LEN_B <= 1)
		return ;
	ft_rev_rotate_b(stacks);
	rb_insert(root, (root->count + 1), "rrb\n");
}

void	ft_rev_rot_both(t_stacks *stacks, t_rbroot *root)
{
	if (LEN_A <= 1 && LEN_B <= 1)
		return ;
	ft_rev_rotate_both(stacks);
	rb_insert(root, (root->count + 1), "rrr\n");
}
