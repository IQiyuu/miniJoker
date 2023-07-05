/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:05:53 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/05 15:36:07 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

static char	**quit(char **res)
{
	mini_freetab(res);
	return (NULL);
}

int	mini_len(char *str, char **charset, int i)
{
	char	quote;
	int		size;

	size = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		if (mini_is_intab(charset, &str[i]))
			break ;
		while (str[i] && !mini_is_intab(charset, &str[i]) && str[i] != ' ')
		{
			if (str[i] == '\"' || str[i] == '\'')
			{
				quote = str[i++];
				while (str[i] && str[i++] != quote)
					size++;
			}
			else
			{
				size++;
				i++;
			}
		}
		if (str[i] && str[i] == ' ')
			break ;
	}
	if (mini_is_intab(charset, &str[i]) && size == 0)
		size++;
	return (size);
}

char	*ministrdup(char *str, char **charset, int	*i)
{
	char	*res;
	int		size;
	char	quote;
	int		j;

	size = mini_len(str, charset, *i);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	while (str[*i])
	{
		if (mini_is_intab(charset, &str[*i]))
			break ;
		while (str[*i] && !mini_is_intab(charset, &str[*i]) && str[*i] != ' ')
		{
			if (str[*i] == '\"' || str[*i] == '\'')
			{
				quote = str[(*i)++];
				while (str[*i] && str[(*i)++] != quote)
					res[j++] = str[(*i) - 1];
			}
			else
				res[j++] = str[(*i)++];
		}
		if (str[*i] && str[*i] == ' ')
			break ;
	}
	if (mini_is_intab(charset, &str[*i]) && size == 1)
		res[j++] = str[(*i)++];
	res[j] = '\0';
	return (res);
}

int	nb_of_words(char *str, char **charset)
{
	int	cpt;
	int	i;
	int	quote;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		cpt++;
		if (!str[i])
			break ;
		if (mini_is_intab(charset, &str[i]))
			i++;
		while (str[i] && !mini_is_intab(charset, &str[i]) && str[i] != ' ')
		{
			if (str[i] == '\"' || str[i] == '\'')
			{
				quote = str[i++];
				while (str[i] && str[i++] != quote)
					;
			}
			else
				i++;
		}
	}
	return (cpt);
}

int	stris_encapsuled(char *str)
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
	return (quote == '\0');
}

char	**mini_split(char *str, char **charset)
{
	char	**res;
	int		size;
	int		i;
	int		j;

	if (!str || !stris_encapsuled(str))
		return (NULL);
	size = nb_of_words(str, charset);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		NULL;
	i = 0;
	j = 0;
	while (i < size)
	{
		res[i] = ministrdup(str, charset, &j);
		if (!res[i])
			return (quit(res));
		i++;
	}
	res[i] = NULL;
	return (res);
}
