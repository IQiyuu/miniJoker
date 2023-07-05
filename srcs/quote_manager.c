/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:23:00 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/05 13:14:52 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

char	*simpledup_without_quote(char *str)
{
	char	quote;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	quote = '\0';
	tmp = (char *)malloc(sizeof(char) * (encapsuled_strlen(str) + 1));
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

int	size_encapsuled(char **tab, int *i, char quote)
{
	int	k;
	int	r;
	int	size;

	size = 0;
	k = *i;
	r = 0;
	while (tab[k])
	{
		size += mini_strlen(tab[k]);
		if (str_is_encapsuled(tab[k]) == quote)
			r++;
		if (r == 2)
			break ;
		k++;
	}
	size += k - *i;
	return (size);
}

char	*copy_until_encapsuled(char **tab, int *i, int *kr, char quote)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (size_encapsuled(tab, i, quote) + 1));
	if (!tmp)
		return (NULL);
	while (tab[*i])
	{
		if (kr[0] != 0)
			tmp[kr[0]++] = ' ';
		if (str_is_encapsuled(tab[*i]) == quote)
		{
			kr[1]++;
			mini_strcpy(tab[*i], &tmp[kr[0]]);
			kr[0] += mini_strlen(tab[(*i)++]);
		}
		else
		{
			mini_strcpy(tab[*i], &tmp[kr[0]]);
			kr[0] += mini_strlen(tab[(*i)++]);
		}
		if (kr[1] == 2)
			break ;
	}
	tmp[kr[0]] = '\0';
	return (tmp);
}

char	*multipledup_without_quote(char **tab, int *i, char quote)
{
	int		kr[2];
	char	*res;
	char	*tmp;

	kr[0] = 0;
	kr[1] = 0;
	tmp = copy_until_encapsuled(tab, i, kr, quote);
	if (!tmp)
		return (NULL);
	res = simpledup_without_quote(tmp);
	free(tmp);
	return (res);
}

int	remove_encapsuled(t_minijoker *mini)
{
	int		i;
	int		j;
	char	**tmp;

	if (!tab_is_encapsuled(mini->tokens))
		return (QUOTE_ERROR);
	tmp = (char **)malloc(sizeof(char *) * (encap_tablen(mini->tokens) + 1));
	if (!tmp)
		return (MALLOC_ERROR);
	i = 0;
	j = 0;
	while (mini->tokens[i])
	{
		if (str_is_encapsuled(mini->tokens[i]) != '\0')
			tmp[j] = multipledup_without_quote(mini->tokens, &i,
					str_is_encapsuled(mini->tokens[i]));
		else
			tmp[j] = simpledup_without_quote(mini->tokens[i++]);
		if (!tmp[j++])
			return (flemme_exit(tmp));
	}
	tmp[j] = NULL;
	mini_freetab(mini->tokens);
	mini->tokens = tmp;
	return (SUCCESS);
}
