/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:03:49 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/21 14:43:13 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_linked_list(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}

void	double_founded(t_list *lst)
{
	write(2, "Error\n", 6);
	free_linked_list(&lst);
	exit(6);
}

void	check_doubles(t_list *lst)
{
	t_list *tmp1;
	t_list *tmp2;

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