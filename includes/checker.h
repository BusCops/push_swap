/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:45:19 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/30 16:31:41 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);
void	ss_no_write(t_list *a, t_list *b);
void	pa_no_write(t_list **a, t_list **b);
void	pb_no_write(t_list **a, t_list **b);
void	rrr_no_write(t_list **a, t_list **b);
void	rr_no_write(t_list **a, t_list **b);

#endif