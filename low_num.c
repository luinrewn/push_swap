/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:29:43 by mprokope          #+#    #+#             */
/*   Updated: 2025/12/02 06:26:42 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void print_list(t_list *head)
{
    t_list *tmp = head;

    while (tmp)
    {
        ft_printf("val: %d id: [%d]\n", tmp->val, tmp->id);
        tmp = tmp->next;
    }
}
*/

void	sort_4(t_list **list_a, t_list **list_b)
{
	while ((*list_a)->id != 0)
		ra(list_a, list_b);
	if ((*list_a)->id == 0)
		pb(list_a, list_b);
	sort_small(list_a, list_b);
	pa(list_a, list_b);
}

void	sort_5(t_list **list_a, t_list **list_b, int argc)
{
	if (argc == 3)
		ra(list_a, list_b);
	if (argc == 4)
		sort_small(list_a, list_b);
	if (argc == 5)
		sort_4(list_a, list_b);
	if (argc == 6)
	{
		while ((*list_a)->id != 0)
			ra(list_a, list_b);
		if ((*list_a)->id == 0)
			pb(list_a, list_b);
		while ((*list_a)->id != 1)
			rra(list_a, list_b);
		if ((*list_a)->id == 1)
			pb(list_a, list_b);
		sort_small(list_a, list_b);
		pa(list_a, list_b);
		pa(list_a, list_b);
	}
}

void	sort_small(t_list **list_a, t_list **list_b)
{
	int	x;
	int	y;
	int	z;

	x = (*list_a)->val;
	y = (*list_a)->next->val;
	z = (*list_a)->next->next->val;
	if (x > y && y < z && x < z)
		sa(list_a, list_b);
	else if (x > y && y > z)
	{
		sa(list_a, list_b);
		rra(list_a, list_b);
	}
	else if (x > z && y < z)
		ra(list_a, list_b);
	else if (x < y && y > z && x < z)
	{
		rra(list_a, list_b);
		sa(list_a, list_b);
	}
	else if (x < y && y > z && x > z)
	{
		rra(list_a, list_b);
	}
}
