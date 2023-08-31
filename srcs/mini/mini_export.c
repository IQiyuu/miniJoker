/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:24:56 by romartin          #+#    #+#             */
/*   Updated: 2023/08/31 14:08:00 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

static char	**exit_export(char **tmp, char *var)
{
	if (var)
		free(var);
	mini_freetab(tmp);
	mini_putstr_fd(2, "export: malloc failed");
	return (NULL);
}

static void	print_sorted(char **env)
{
	int		i;
	int		j;
	char	**closed;
	char	*low;

	i = 0;
	closed = (char **)malloc(sizeof(char *) * (mini_tablen(env) + 1));
	closed[i] = NULL;
	while (i < mini_tablen(env))
	{
		j = 0;
		low = NULL;
		while (env[j])
		{
			if (!mini_is_intab(closed, env[j], 0)
				&& (low == NULL || mini_strcmp(low, env[j], 0) > 0))
				low = env[j];
			j++;
		}
		closed[i++] = low;
		closed[i] = NULL;
		printf("%s\n", low);
	}
	free(closed);
}

static char	**copy_tab(t_minijoker *mini, char **str, int i)
{
	char	**tmp;
	char	*var;

	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (mini->env_copy[i])
	{
		var = mini_cut_to(mini->env_copy[i], '=');
		if (!var)
			return (exit_export(tmp, var));
		if (mini_strcmp(var, str[0], 0) == 0)
			tmp[i] = mini_strdup(mini->tokens->content);
		else
			tmp[i] = mini_strdup(mini->env_copy[i]);
		if (!tmp[i])
			return (exit_export(tmp, var));
		free(var);
		i++;
	}
	if (get_env(mini, str[0]) == NULL)
		tmp[i++] = mini_strdup(mini->tokens->content);
	tmp[i] = NULL;
	return (tmp);
}

static void	mini_export_bis(t_minijoker *mini, char **str)
{
	int		i;
	char	**tmp;

	if (!str[0])
		return (mini_freetab(str));
	if (mini->tokens->content[0] == '=')
	{
		mini_putstr_fd(2, "minijoker: export: `");
		mini_putstr_fd(2, mini->tokens->content);
		mini_putstr_fd(2, "': not a valid identifier\n");
		mini->error = INPUT_ERROR;
	}
	i = mini_tablen(mini->env_copy);
	if (get_env(mini, str[0]) == NULL)
		i++;
	tmp = copy_tab(mini, str, i);
	if (!tmp)
		return ;
	mini_freetab(mini->env_copy);
	mini->env_copy = tmp;
	mini_freetab(str);
	mini->tokens = mini->tokens->next;
}

void	mini_export(t_minijoker *mini)
{
	char	**str;

	mini->error = SUCCESS;
	mini->tokens = mini->tokens->next;
	if (!mini->tokens || !mini->tokens->content
		|| mini_is_intab(mini->sep, mini->tokens->content, 1))
	{
		print_sorted(mini->env_copy);
		return ;
	}
	str = mini_ft_split(mini->tokens->content, '=');
	if (!str)
	{
		mini->error = MALLOC_ERROR;
		mini_putstr_fd(2, "minijoker: export: malloc failed\n");
		return ;
	}
	mini_export_bis(mini, str);
}
