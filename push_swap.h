/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 23:24:57 by mprokope          #+#    #+#             */
/*   Updated: 2025/11/23 23:25:22 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/src/libft.h"

typedef struct s_list
{
	long			val;
	int				id;
	struct s_list	*next;
}				t_list;

void	print_list(t_list *head);
int		in_max(t_list *list_a);
int		indexx(t_list *list_a);
int		check_num(int argc, char **argv);
int		dup_check(t_list *list_a);
void	radix(t_list **list_a, t_list **list_b);
t_list	*ra(t_list **list_a);
t_list	*pb(t_list **list_a, t_list **list_b);
t_list	*pa(t_list **list_a, t_list **list_b);

#endif
