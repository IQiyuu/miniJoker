/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:23:00 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/03 16:17:23 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int	mini_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*mini_without_quote(char *str)
{
	return (NULL);
}

int	remove_encapsuled(char **tokens)
{
	int i;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * (mini_tablen(tokens) + 1));
	i = 0;
	while (tokens[i])
	{
		if (ft_charfind(tokens[i], '\'') != ft_strlen(tokens[i]) && 
			ft_charfind(tokens[i], '\"') != ft_strlen(tokens[i]))
			tmp[i] = mini_without_quote(tokens[i]);
		else
			tmp[i] = ft_strdup(tokens[i]);
	}
	return (EXIT_SUCCESS);
}