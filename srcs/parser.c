/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:34:13 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/09 18:18:44 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"
/*
void	parse_dol_bis(t_token **nt, char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '$')
		{
			mini_tokenadd_back(nt,
				mini_tokennew(mini_cut_to(&tmp[i], ' '), OTHER));
			while (tmp[i] && tmp[i] != ' ')
				i++;
			if (tmp[i])
				i++;
		}
		if (!tmp[i])
			break ;
		mini_tokenadd_back(nt,
			mini_tokennew(mini_cut_to(&tmp[i], '$'), OTHER));
		while (tmp[i] && tmp[i] != '$')
			i++;
	}
}

void	parse_dol(t_token *tokens)
{
	char	*tmp;
	t_token	*nt;

	while (tokens)
	{
		nt = NULL;
		if (mini_charfind(tokens->content, '$') < mini_strlen(tokens->content))
		{
			tmp = tokens->content;
			parse_dol_bis(&nt, tmp);
			nt->prev = tokens->prev;
			mini_tokenlast(nt)->next = tokens->next;
			if (tokens->prev)
				tokens->prev->next = nt;
			if (tokens->next)
				tokens->next->prev = nt;
		}
		tokens = tokens->next;
	}
}

void	parser(t_minijoker *mini, char *input)
{
	if (!input)
	{
		mini->tokens = NULL;
		mini->error = END;
		return ;
	}
	mini->tokens = mini_split(input, mini->sep, &mini->error);
	parse_dol(mini->tokens);
	parse_env(mini, mini->tokens);
	if (mini->error == QUOTE_ERROR)
	{
		mini_putstr_fd(2, "parsing error: quote unclosed\n");
		return ;
	}
	if (mini->tokens && mini_strcmp(mini->tokens->content, "exit", 0) == 0)
	{
		mini->end = 1;
		return ;
	}
}
*/

t_token	*quit(t_token *tokens)
{
	mini_tokenclear(tokens);
	return (NULL);
}

static int	mini_len2(char *str, char **charset, int i)
{
	int	j;
	char	quote;

	quote = '\0';
	j = i;
	while (str[j] && str[j] == ' ')
		j++;
	while (str[j])
	{
		if (!quote && (str[j] == '\'' || str[j] == '\"'))
			quote = str[j];
		else if (quote && str[j] == quote)
			quote = '\0';
		if (mini_is_intab(charset, &str[j], 1) && !quote)
			break ;
		if (str[j] == ' ' && !quote)
			break ;
		j++;
	}
	if (mini_is_intab(charset, &str[j], 1))
	{
		j++;
		if (str[j] == '<' || str[j] == '>')
			j++;
	}
	return (j - i);
}

static int	fill(char *str, char **charset, char *res, int *i)
{
	int		j;
	char	quote;

	quote = '\0';
	j = 0;
	while (str[*i])
	{
		if (!quote && (str[*i] == '\'' || str[*i] == '\"'))
			quote = str[*i];
		else if (quote && str[*i] == quote)
			quote = '\0';
		if (mini_is_intab(charset, &str[*i], 1) && !quote)
			break ;
		if (str[*i] == ' ' && !quote)
			break ;
		res[j++] = str[(*i)++];
	}
	return (j);
}

char	*ministrdup2(char *str, char **charset, int	*i)
{
	char	*res;
	int		size;
	int		j;

	j = 0;
	size = mini_len2(str, charset, *i);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	j = fill(str, charset, res, i);
	if (mini_is_intab(charset, &str[*i], 1))
	{
		if (mini_is_intab(charset, &str[*i], 1) == 2)
			res[j++] = str[(*i)++];
		res[j++] = str[(*i)++];
	}
	res[j] = '\0';
	return (res);
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
		else if (quote == str[i])
			quote = '\0';
		i++;
	}
	return (quote == '\0');
}

static t_token	*assignation(char *str, char **charset)
{
	int		i;
	t_token	*tokens;
	char	*content;
	int		plop;

	i = 0;
	tokens = NULL;
	while (str[i])
	{
		if (!mini_strcmp(" '|'", &str[i], 1)
			|| !mini_strcmp(" \"|\"", &str[i], 1))
			plop = PARAM;
		else
			plop = OTHER;
		content = ministrdup2(str, charset, &i);
		if (!content)
			return (quit(tokens));
		if (!mini_tokenadd_back(&tokens, mini_tokennew(content, plop)))
			return (quit(tokens));
	}
	return (tokens);
}

t_token	*mini_split2(char *str, char **charset, int *error)
{	
	if (!str)
		return (NULL);
	if (!stris_encapsuled(str))
	{
		*error = QUOTE_ERROR;
		return (NULL);
	}
	return (assignation(str, charset));
}

int	mini_len3(char *str)
{
	int	i;
	int	size;
	char	quote;

	quote = '\0';
	i = 0;
	size = 0;
	while (str[i])
	{
		if (!quote && str[i] == '\'')
			quote = '\'';
		else if (quote && str[i] == quote)
			quote = '\0';
		else
			size++;
		i++;
	}
	return (size);
}

void	delete_singlequote(t_minijoker *mini)
{
	int	i;
	int	size;
	char	quote;
	char	*str;
	int		j;
	t_token	*first;

	first = mini->tokens;
	while (mini->tokens)
	{
		size = mini_len3(mini->tokens->content);
		if (size != mini_strlen(mini->tokens->content))
		{
			// mettre dans une fct cpy_witout_single
			quote = '\0';
			i = 0;
			j = 0;
			str = (char *)malloc(sizeof(char) * (size + 1));
			while (mini->tokens->content[i])
			{
				if (!quote && mini->tokens->content[i] == '\'')
					quote = '\'';
				else if (quote && mini->tokens->content[i] == quote)
					quote = '\0';
				else
					str[j++] = mini->tokens->content[i];
				i++;
			}
			str[j] = '\0';
			free(mini->tokens->content);
			mini->tokens->content = str;
		}
		mini->tokens = mini->tokens->next;
	}
	mini->tokens = first;
}

int	is_func(t_minijoker *mini, char *str)
{
	char	**argv;
	int		i;

	argv = mini_ft_split(get_env(mini, "PATH"), ':');
	i = 0;
	while (argv[i])
	{
		if (mini_is_valid_func(argv[i], str))
		{
			freetab(argv);
			return (1);
		}
		i++;
	}
	freetab(argv);
	return (0);
}

char	*mini_cut_to2(char *str, char *charset)
{
	int	i;
	char	**tab;
	char	*res;

	i = 0;
	tab = mini_ft_split(charset, ' ');
	while (str[i++])
		if (mini_is_intab(tab, &str[i], 1) || str[i] == ' ')
			break ;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
	{
		free(tab);
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		if (mini_is_intab(tab, &str[i], 1) || str[i] == ' ')
			break ;
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	mini_len4(t_minijoker *mini, char *str)
{
	int	size;
	char	quote;
	int	i;
	char	*tmp;

	size = 0;
	i = 0;
	quote = '\0';
	while (str[i])
	{
		if (str[i] == '\"')
		{
			if (!quote)
				quote = str[i];
			else if (quote == str[i])
				quote = '\0';
			else
				size++;
			i++;
		}
		else if (str[i] == '\'')
		{
			if (!quote)
				quote = str[i];
			else if (quote == '\'')
				quote = '\0';
			else
				size++;
			i++;
		}
		else if ((!quote || quote == '\"') && (str[i] == '$'))
		{
			tmp = mini_cut_to2(&mini->tokens->content[i + 1], "\' \" > >> << <");
			if (get_env(mini, tmp) != NULL)
				size += mini_strlen(get_env(mini, tmp));
			else if (mini->tokens->content[i + 1] == '?')
			{
				free(tmp);
				tmp = mini_itoa(mini->lerror);
				size += mini_strlen(tmp);
			}
			if (mini_strlen(tmp) == 0)
			{
				size++;
				i++;
			}
			else
				i += mini_strlen(tmp) + 1;
			free(tmp);
		}
		else
		{
			i++;
			size++;
		}
	}
	return (size);
}

void	jsp(t_minijoker *mini)
{
	int	i;
	char	quote;
	t_token	*token;
	int		size;
	int		j;
	char	*str;
	char	*tmp;

	token = mini->tokens;
	while (mini->tokens)
	{
		size = mini_len4(mini, mini->tokens->content);
		if (size != mini_strlen(mini->tokens->content))
		{
			str = (char *)malloc(sizeof(char) * (size + 1));
			i = 0;
			j = 0;
			quote = '\0';
			while (mini->tokens->content[i])
			{
				if (mini->tokens->content[i] == '\'')
				{
					if (!quote)
						quote = mini->tokens->content[i];
					else if (quote == '\'')
						quote = '\0';
					else
						str[j++] = mini->tokens->content[i];
					i++;
				}
				else if (mini->tokens->content[i] == '\"')
				{
					if (!quote)
						quote = mini->tokens->content[i];
					else if (quote == '\"')
						quote = '\0';
					else
						str[j++] = mini->tokens->content[i];
					i++;
				}
				else if ((!quote || quote == '\"') && (mini->tokens->content[i] == '$'))
				{
					tmp = mini_cut_to2(&mini->tokens->content[i + 1], "\' \" > >> << <");
					if (get_env(mini, tmp) != NULL)
					{
						str[j] = '\0';
						mini_stradd(str, get_env(mini, tmp));
						j = mini_strlen(str);
					}
					else if (mini->tokens->content[i + 1] == '?')
					{
						str[j] = '\0';
						free(tmp);
						tmp = mini_itoa(mini->lerror);
						mini_stradd(str, tmp);
						j = mini_strlen(str);
					}
					if (mini_strlen(tmp) == 0)
						str[j++] = mini->tokens->content[i++];
					else
						i += mini_strlen(tmp) + 1;
					free(tmp);
				}
				else
					str[j++] = mini->tokens->content[i++];
			}
			str[j] = '\0';
			free(mini->tokens->content);
			mini->tokens->content = str;
		}
		mini->tokens = mini->tokens->next;
	}
	mini->tokens = token;
}

void	parser(t_minijoker *mini, char *input)
{
	if (!input)
	{
		mini->tokens = NULL;
		mini->error = END;
		return ;
	}
	mini->tokens = mini_split2(input, mini->sep, &mini->error);
	jsp(mini);
	if (mini->tokens && mini_strcmp(mini->tokens->content, "exit", 0) == 0)
	{
		mini->end = 1;
		return ;
	}
}
