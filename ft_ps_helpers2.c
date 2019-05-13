/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:09:02 by lshanaha          #+#    #+#             */
/*   Updated: 2019/03/02 18:20:18 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_worker1(t_rbroot *root, int data1, int data2, int *i)
{
	t_rbnode	*temp;

	temp = ft_rbtree_datasearch(root, data1);
	ft_rbtree_del(root, data2);
	if (!temp)
		return ;
	temp->text = "ss\n";
	*i = ft_rbtree_min(root->root) - 1;
}

static void		ft_worker2(t_rbroot *root, t_rbnode **f, int data2, int *i)
{
	(*f)->text = "rr\n";
	ft_rbtree_del(root, data2);
	*i = ft_rbtree_min(root->root) - 1;
}

static void		ft_worker3(t_rbroot *root, t_rbnode **f, int data2, int *i)
{
	(*f)->text = "rrr\n";
	ft_rbtree_del(root, data2);
	*i = ft_rbtree_min(root->root) - 1;
}

static void		ft_func(t_rbroot *root, t_rbnode *f, t_rbnode *s, int *i)
{
	if ((!ft_strcmp(f->text, "pa\n") && !ft_strcmp(s->text, "pb\n")) ||
	(!ft_strcmp(f->text, "pb\n") && !ft_strcmp(s->text, "pa\n")))
		ft_worker(root, f->data, s->data, i);
	else if ((!ft_strcmp(f->text, "ra\n") && !ft_strcmp(s->text, "rra\n"))\
	|| (!ft_strcmp(f->text, "rra\n") && !ft_strcmp(s->text, "ra\n")))
		ft_worker(root, f->data, s->data, i);
	else if (!ft_strcmp(f->text, "rb\n") && !ft_strcmp(s->text, "rrb\n"))
		ft_worker(root, f->data, s->data, i);
	else if (!ft_strcmp(f->text, "rrb\n") && !ft_strcmp(s->text, "rb\n"))
		ft_worker(root, f->data, s->data, i);
	else if ((!ft_strcmp(f->text, "sa\n") && !ft_strcmp(s->text, "sb\n")) ||
	(!ft_strcmp(f->text, "sb\n") && !ft_strcmp(s->text, "sa\n")))
		ft_worker1(root, f->data, s->data, i);
	else if ((!ft_strcmp(f->text, "ra\n") && !ft_strcmp(s->text, "rb\n"))\
	|| (!ft_strcmp(f->text, "rb\n") && !ft_strcmp(s->text, "ra\n")))
		ft_worker2(root, &f, s->data, i);
	else if ((!ft_strcmp(f->text, "rra\n") && !ft_strcmp(s->text, "rrb\n"))\
	|| (!ft_strcmp(f->text, "rrb\n") && !ft_strcmp(s->text, "rra\n")))
		ft_worker3(root, &f, s->data, i);
}

void			ft_tree_optimize(t_rbroot *root, t_rbnode *f, t_rbnode *s,\
int i)
{
	int	temp;

	(root->root) ? i = ft_rbtree_min(root->root) - 1 : 0;
	(root->root) ? temp = ft_rbtree_max(root->root) : 0;
	while (++i < temp)
	{
		f = ft_rbtree_datasearch(root, i);
		s = ft_rbtree_next(root, i);
		if (!f || !s || !(f->text) || !(s->text))
			continue ;
		ft_func(root, f, s, &i);
	}
}
