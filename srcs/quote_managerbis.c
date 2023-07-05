/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_managerbis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:02:58 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/05 13:15:34 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int	encap_tablen(char **tab)
{
	char	quote;
	int		i;
	int		j;
	int		cpt;

	i = 0;
	cpt = 0;
	quote = '\0';
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (quote == '\0' && (tab[i][j] == '\'' || tab[i][j] == '\"'))
				quote = tab[i][j];
			else if (quote != '\0' && quote == tab[i][j])
				quote = '\0';
			j++;
		}
		if (quote == '\0')
			cpt++;
		i++;
	}
	return (cpt);
}

int	encapsuled_strlen(char *str)
{
	int		i;
	int		cpt;
	char	quote;

	quote = '\0';
	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (quote == '\0' && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote != '\0' && quote == str[i])
			quote = '\0';
		else
			cpt++;
		i++;
	}
	return (cpt);
}

int	tab_is_encapsuled(char **tab)
{
	char	quote;
	int		i;
	int		j;

	quote = '\0';
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (quote == '\0' && (tab[i][j] == '\'' || tab[i][j] == '\"'))
				quote = tab[i][j];
			else if (quote != '\0' && quote == tab[i][j])
				quote = '\0';
			j++;
		}
		i++;
	}
	return (quote == '\0');
}

char	str_is_encapsuled(char *str)
{
	char	quote;
	int		i;

	i = 0;
	quote = '\0';
	while (str[i])
	{
		if (quote == '\0' && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote != '\0' && quote == str[i])
			quote = '\0';
		i++;
	}
	return (quote);
}

int	flemme_exit(char **tab)
{
	mini_freetab(tab);
	return (MALLOC_ERROR);
}
