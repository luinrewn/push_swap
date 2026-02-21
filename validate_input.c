/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 02:06:18 by mprokope          #+#    #+#             */
/*   Updated: 2026/01/02 19:47:19 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alr_sorted(t_list *list_a)
{
	t_list	*temp;

	while (list_a->next)
	{
		temp = list_a->next;
		if (list_a->id != (temp->id - 1))
			return (0);
		list_a = list_a->next;
	}
	return (1);
}

static int	minus(char **argv)
{
	int	i;
	int	count;

	i = 0;
	while (argv[i])
	{
		count = ft_strlen(argv[i]);
		if (count == 1 && argv[i][0] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	dup_check(t_list *list_a)
{
	t_list	*temp;
	t_list	*iter;

	temp = list_a;
	while (temp)
	{
		iter = list_a;
		while (iter)
		{
			if (temp != iter && temp->val == iter->val)
				return (1);
			iter = iter->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	check_num(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			if (minus(argv) || (j != 0 && argv[i][j] == '-'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	in_max(t_list *list_a, char **argv)
{
	int	i;
	int	j;
	int	min;

	i = 1;
	while (argv[i])
	{
		j = 0;
		min = 10;
		while (argv[i][j])
			j++;
		if (argv[i][0] == '-')
			min = 11;
		if (j > min)
			return (1);
		i++;
	}
	while (list_a)
	{
		if (list_a->val < -2147483648 || list_a->val > 2147483647)
			return (1);
		list_a = list_a->next;
	}
	return (0);
}
