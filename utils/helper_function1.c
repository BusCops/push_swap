/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:09:17 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/23 15:10:56 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_copy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
}

char	*ft_strdup(char *str)
{
	int		len;
	char	*s;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_copy(s, str);
	s[len] = '\0';
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*t1;
	unsigned const char	*t2;

	if (!dst && !src)
		return (NULL);
	if (src == dst)
		return (dst);
	t2 = (unsigned const char *)src;
	t1 = (unsigned char *)dst;
	while (n > 0)
	{
		*t1 = *t2;
		t1++;
		t2++;
		n--;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_copy(str, s1);
	ft_copy(str + ft_strlen(s1), s2);
	str[len] = '\0';
	return (str);
}
