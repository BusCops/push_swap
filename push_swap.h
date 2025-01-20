/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:55:42 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/20 16:02:42 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

char	**args_check(int ac, char **av);
void	arg_num_check(int ac);
void	arg_check_int(char **av);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**args_combinor(char **av);
void	free_array(char **str);
int		ft_strlen(char *str);
int		ft_atoi(char *str, char **args);
void	wrong_number(char **args);

#endif