/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:40:08 by mprokope          #+#    #+#             */
/*   Updated: 2025/11/23 23:36:48 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//t_list  *sa(t_list *list_a);

t_list	*inputlist(int argc, char **argv)
{
	t_list	*new;
	t_list	*ret;
	t_list	*head;
	int		i;	

	head = NULL;
	ret = NULL;
	i = 1;
	while (i < argc && argv[i])
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (NULL);
		new->val = ft_atol(argv[i]);
		new->next = NULL;
		if (!head)
			head = new;
		else
			ret->next = new;
		ret = new;
		i++;
	}
	return (head);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
		return (0);
	if (check_num(argc, argv))
		return (ft_printf("%e\n", "Error"));
	list_a = inputlist(argc, argv);
	list_b = NULL;
	if (dup_check(list_a) || in_max(list_a))
		return (-1);
	radix(&list_a, &list_b);
}
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
// change index depending on number of tenth
/*t_list	*indexing(t_list *list_a)
{
	int	i;

	while (list_a->next)
	{
		i = 0;
		if (list_a->val < 0)
			list_a->val = -1;
		while ((list_a->val / 10) > 0)
			i++;
		list_a->val = i;
		list_a = list_a->next;
	}
}
*/
/*
int	get_max(t_list *list_a)
{
	t_list	*temp;
	int		max;

	temp = list_a;
	max = -2147483648;
	while (temp)
	{
		if (temp->val > max)
			max = temp->val;
		temp = temp->next;
	}
	return (max);
}
*/
	//MY PRINTLIST FUNCTION
	//print_list(list_a);
	/*while (temp->next)
	{
		next_one = temp->next;
		if (temp->val > next_one->val)
		{
			temp = sa(temp);
			ft_printf("sa\n");
			temp = list_a;
			i++;
		}
		else
			temp = temp->next;
	}*/
	//print_list(list_a);
	//while (i)
	//	ft_printf("sa\n", i--);
	//ft_printf("Number of Circles: %d\n", i);
