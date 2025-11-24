/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 02:06:18 by mprokope          #+#    #+#             */
/*   Updated: 2025/11/23 23:56:46 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				return (ft_printf("%e\n", "Error"), 1);
			iter = iter->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	check_num(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	(void)argc;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	in_max(t_list *list_a)
{
	while (list_a)
	{
		if (list_a->val < -2147483648 || list_a->val > 2147483647)
			return (ft_printf("%e\n", "Error"), 1);
		list_a = list_a->next;
	}
	return (0);
}
