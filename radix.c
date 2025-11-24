/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:47:13 by mprokope          #+#    #+#             */
/*   Updated: 2025/11/23 23:23:50 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexx(t_list *list_a)
{
	t_list	*temp;
	t_list	*small;
	int		indx;
	int		biggest;

	temp = list_a;
	biggest = -1;
	while (temp)
	{
		small = list_a;
		indx = 0;
		while (small)
		{
			if (small->val < temp->val)
				indx++;
			small = small->next;
		}
		if (indx > biggest)
			biggest = indx;
		temp->id = indx;
		temp = temp->next;
	}
	return (biggest);
}

int	max_bits(int max)
{
	int	i;

	i = 0;
	while (max >> i != 0)
		i++;
	return (i);
}

int	lst_i(t_list *list_a)
{
	int	i;

	i = 0;
	while (list_a)
	{
		i++;
		list_a = list_a->next;
	}
	return (i);
}

void	radix(t_list **list_a, t_list **list_b)
{
	int	max;
	int	i;
	int	j;
	int	size;

	max = max_bits(indexx(*list_a));
	size = lst_i(*list_a);
	i = 0;
	while (i < max)
	{
		j = size;
		while (j--)
		{
			if (((*list_a)->id >> i) & 1)
				ra(list_a);
			else
				pb(list_a, list_b);
		}
		while (*list_b)
			pa(list_a, list_b);
		i++;
	}
}
