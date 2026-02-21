/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:40:08 by mprokope          #+#    #+#             */
/*   Updated: 2026/01/02 19:42:41 by mprokope         ###   ########.fr       */
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
			return (nuke(&head, &new), NULL);
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

void	nuke(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	while (*list_a)
	{
		temp = (*list_a)->next;
		free(*list_a);
		*list_a = temp;
	}
	while (*list_b)
	{
		temp = (*list_b)->next;
		free(*list_b);
		*list_b = temp;
	}
}

void	radix_runner(t_list **list_a, t_list **list_b, int max)
{
	int	i;

	i = 0;
	radix(list_a, list_b, max, i);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		max;

	if (argc < 2)
		return (0);
	if (check_num(argv))
		return (write(2, "Error\n", 6));
	list_a = inputlist(argc, argv);
	if (!list_a)
		exit(1);
	max = indexx(list_a);
	list_b = NULL;
	if (dup_check(list_a) || in_max(list_a, argv))
	{
		nuke(&list_a, &list_b);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (alr_sorted(list_a))
		return (nuke(&list_a, &list_b), 0);
	if (argc < 7)
		return (sort_5(&list_a, &list_b, argc), nuke(&list_a, &list_b), 0);
	radix_runner(&list_a, &list_b, max);
	nuke(&list_a, &list_b);
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
