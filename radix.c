/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:47:13 by mprokope          #+#    #+#             */
/*   Updated: 2025/12/30 00:38:08 by mprokope         ###   ########.fr       */
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

void	radix(t_list **list_a, t_list **list_b, int max, int i)
{
	int	j;
	int	size;

	while (i++ < max_bits(max))
	{
		j = 0;
		size = lst_i(*list_a);
		while (j < size)
		{
			if (!(*list_a))
				exit(1);
			if (((*list_a)->id >> (i - 1)) & 1)
				ra(list_a, list_b);
			else
				pb(list_a, list_b);
			j++;
		}
		while (*list_b)
		{
			pa(list_a, list_b);
			if (!(*list_a))
				exit(1);
		}
	}
}
