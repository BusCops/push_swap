/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:03:49 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/21 17:46:06 by abenzaho         ###   ########.fr       */
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

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
