/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 23:24:57 by mprokope          #+#    #+#             */
/*   Updated: 2026/01/02 19:42:20 by mprokope         ###   ########.fr       */
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

void	sort_small(t_list **list_a, t_list **list_b);
void	sort_5(t_list **list_a, t_list **list_b, int argc);
int		alr_sorted(t_list *list_a);
void	nuke(t_list **list_a, t_list **list_b);
int		in_max(t_list *list_a, char **argv);
int		indexx(t_list *list_a);
int		check_num(char **argv);
int		dup_check(t_list *list_a);
void	radix(t_list **list_a, t_list **list_b, int max, int i);
void	radix_runner(t_list **list_a, t_list **list_b, int max);
t_list	*ra(t_list **list_a, t_list **list_b);
t_list	*pb(t_list **list_a, t_list **list_b);
t_list	*pa(t_list **list_a, t_list **list_b);
t_list	*rra(t_list **list_a, t_list **list_b);
t_list	*sa(t_list **list_a, t_list **list_b);
#endif
