/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 23:28:44 by mprokope          #+#    #+#             */
/*   Updated: 2025/11/23 23:29:27 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ra(t_list **list_a)
{
	t_list	*start;
	t_list	*end;

	if (!list_a || !(*list_a) || !(*list_a)->next)
		return (*list_a);
	start = *list_a;
	*list_a = (*list_a)->next;
	end = *list_a;
	while (end->next)
		end = end->next;
	end->next = start;
	start->next = NULL;
	ft_printf("ra\n");
	return (*list_a);
}

t_list	*pa(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (!list_b || !(*list_b))
		return (*list_a);
	temp = *list_b;
	*list_b = (*list_b)->next;
	temp->next = *list_a;
	*list_a = temp;
	ft_printf("pa\n");
	return (*list_a);
}

t_list	*pb(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (!list_a || !(*list_a))
		return (*list_b);
	temp = *list_a;
	*list_a = (*list_a)->next;
	temp->next = *list_b;
	*list_b = temp;
	ft_printf("pb\n");
	return (*list_b);
}

/*
t_list	*sa(t_list *list_a)
{
	t_list	*temp;
	int		i;
	int		j;

	if (!list_a || !list_a->next)
		return (list_a);
	temp = list_a->next;
	i = list_a->val;
	list_a->val = temp->val;
	temp->val = i;
	j = list_a->id;
	list_a->id = temp->id;
	temp->id = j;
	return (list_a);
}

t_list	*sb(t_list *list_b)
{
	t_list	*temp;
	int		i;
	int		j;

	if (!list_b || !list_b->next)
		return (list_b);
	temp = list_b->next;
	i = list_b->val;
	list_b->val = temp->val;
	temp->val = i;
	j = list_b->id;
	list_b->id = temp->id;
	temp->id = j;
	return (list_b);
}

void	ss(t_list *list_a, t_list *list_b)
{
	sb(list_b);
	sa(list_a);
	ft_printf("ss\n");
}

void	reverse_list(t_list **start)
{
	t_list	*prev;
	t_list	*temp;
	t_list	*next;

	temp = (*begin);
	prev = NULL;
	next = NULL;
	while (temp)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	*begin = prev;
}
t_list	*rb(t_list **list_b)
{
	t_list	*start;
	t_list	*end;

	if (!list_b || !(*list_b) || !(*list_b)->next)
		return (*list_b);
	start = *list_b;
	*list_b = (*list_b)->next;
	end = *list_b;
	while(end->next)
		end = end->next;
	end->next = start;
	start->next = NULL;
	return (*list_b);
}

void	rr(t_list **list_a, t_list **list_b)
{
	ra(list_a);
	rb(list_b);
	ft_printf("ra\n");
}

t_list	*rrb(t_list **list_b)
{
	t_list	*start;
	t_list	*end;

	if (!list_b || !(*list_b) || !(*list_b)->next)
		return (*list_b);
	start = NULL;
	end = *list_b;
	while (end->next)
	{
		start = end;
		end = end->next;
	}
	start->next = NULL;
	end->next = *list_b;
	*list_b = end;
	return (*list_b);
}

t_list	*rra(t_list **list_a)
{
	t_list	*start;
	t_list	*end;

	if (!list_a || !(*list_a) || !(*list_a)->next)
		return (*list_a);
	start = NULL;
	end = *list_a;
	while (end->next)
	{
		start = end;
		end = end->next;
	}
	start->next = NULL;
	end->next = *list_a;
	*list_a = end;
	return (*list_a);
}

void	rrr(t_list **list_a, t_list **list_b)
{
	rra(list_a);
	rrb(list_b);
	ft_printf("rrr\n");
}
*/
