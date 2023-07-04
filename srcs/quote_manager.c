/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:23:00 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/04 12:46:06 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* /!\ W.I.P /!\ */
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
	static char	quote = '\0';
	int		i;
	int		cpt;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
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
	{
		quote = '\0';
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (cpt + 1));
	if (!tmp)
		return (NULL);
	i = 0;
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
/* A FAIRE : */
/* */
/* - pour compter le nombre de case faire cpt++; et et quand je trouve un " ou ' ne pas faire cpt++ jusqu au prochain */
/* /!\ Se stop a chaque fois que tu trouves un separateur (hors espace) /!\ */
/* /!\ Ne pas recopier si je trouve pas les " ou ' fermantes /!\ */
/* */
/* - pour recopier addtionner les cases en comptant espace entre chaque */
int	remove_encapsuled(t_minijoker *mini)
{
	int i;
	char	**tmp;

	//if (!is_encapsuled(mini->tokens))
		
	tmp = (char **)malloc(sizeof(char *) * (mini_tablen(mini->tokens) + 1));
	i = 0;
	while (mini->tokens[i])
	{
		if (mini_charfind(mini->tokens[i], '\'') != (int)mini_strlen(mini->tokens[i]) ||
			mini_charfind(mini->tokens[i], '\"') != (int)mini_strlen(mini->tokens[i]))
			tmp[i] = mini_without_quote(mini->tokens[i]);
		else
			tmp[i] = mini_strdup(mini->tokens[i]);
		if (!tmp[i])
		{
			mini_freetab(tmp);
			return (EXIT_FAILLURE);
		}
		i++;
	}
	tmp[i] = NULL;
	mini_freetab(mini->tokens);
	mini->tokens = tmp;
	return (EXIT_SUCCESS);
}
