/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:23:00 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/03 17:40:13 by dgoubin          ###   ########.fr       */
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
	char	quote;
	int		i;
	int		cpt;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	quote = '\0';
	cpt = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\"' || str[i] == '\''))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = '\0';
		else
			cpt++;
		i++;
	}
	if (quote)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (cpt + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	quote = '\0';
	while (str[i])
	{
		if (!quote && (str[i] == '\"' || str[i] == '\''))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = '\0';
		else
			tmp[j++] = str[i];
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

int	remove_encapsuled(t_miniJoker *mini)
{
	int i;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * (mini_tablen(mini->tokens) + 1));
	i = 0;
	while (mini->tokens[i])
	{
		if (ft_charfind(mini->tokens[i], '\'') != (int)ft_strlen(mini->tokens[i]) ||
			ft_charfind(mini->tokens[i], '\"') != (int)ft_strlen(mini->tokens[i]))
			tmp[i] = mini_without_quote(mini->tokens[i]);
		else
			tmp[i] = ft_strdup(mini->tokens[i]);
		if (!tmp[i])
		{
			freetab(tmp);
			return (EXIT_FAILLURE);
		}
		i++;
	}
	tmp[i] = NULL;
	freetab(mini->tokens);
	mini->tokens = tmp;
	return (EXIT_SUCCESS);
}
