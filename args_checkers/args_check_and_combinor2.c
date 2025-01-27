/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check_and_combinor2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:33:34 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/23 16:26:41 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	double_founded(t_list *lst)
{
	write(2, "Error\n", 6);
	free_linked_list(&lst);
	exit(6);
}

void	check_doubles(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = lst;
	tmp2 = lst->next;
	while (tmp1->next)
	{
		while (tmp2)
		{
			if (tmp1->data == tmp2->data)
			{
				double_founded(lst);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp1->next;
	}
}

int	check_if_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (-1);
		a = a->next;
	}
	return (0);
}
