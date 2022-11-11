/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:48:58 by tlemos-m          #+#    #+#             */
/*   Updated: 2022/11/11 22:16:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_memory(char **res, int k)
{
	if (!res[k])
	{
		while (k)
		{
			free(res[k]);
			k--;
		}
		free(res);
		return (0);
	}
	return (0);
}

static char	**create_substr(char **res, char const *s, char c, int i)
{
	int	j;
	int	k;

	k = -1;
	while (k++ < i)
	{
		j = 0;
		while (*s == c)
			s++;
		while (s[j] != c && s[j])
			j++;
		if (((s[j] == c) || s[j] == 0) && s[j - 1] != c)
		{
			res[k] = ft_substr(s, 0, j);
			if (!res[k])
				free_memory(res, k);
		}
		s = s + j;
	}
	res[k - 1] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	if (s[0] != c && s[0] != '\0')
		i++;
	while (s[j])
	{
		if ((s[j] == c && s[j + 1] != c) && s[j + 1])
			i++;
		j++;
	}
	res = malloc((i + 1) * sizeof(char *));
	if (!res)
		return (0);
	create_substr(res, s, c, i);
	return (res);
}