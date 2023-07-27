/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:41:59 by romartin          #+#    #+#             */
/*   Updated: 2023/07/25 16:04:56 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

static char	**exit_unset(char **new_env, char *var)
{
	mini_putstr_fd(2, "malloc faillure\n");
	mini_freetab(new_env);
	if (var)
		free(var);
	return (NULL);
}

static char	**copy_tab(t_minijoker *mini, int i)
{
	char	**new_env;
	char	*var;

	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	i = -1;
	while (mini->env_copy[++i])
	{
		var = mini_cut_to(mini->env_copy[i], '=');
		if (!var)
			return (exit_unset(new_env, NULL));
		if (mini_tokenfindstr(mini->tokens, var) == 0)
		{
			new_env[i] = mini_strdup(mini->env_copy[i]);
			if (!new_env[i])
				return (exit_unset(new_env, var));
		}
		free(var);
	}
	while (mini->tokens && !mini_is_intab(mini->sep, mini->tokens->content, 0))
	{
		if (get_env(mini, mini->tokens->content) != NULL)
			i--;
		mini->tokens = mini->tokens->next;
	}
	new_env[i] = NULL;
	return (new_env);
}

void	mini_unset(t_minijoker *mini)
{
	char	**new_env;
	t_token	*tmp;
	int		i;

	i = 0;
	mini->error = SUCCESS;
	mini->tokens = mini->tokens->next;
	if (!mini->tokens)
		return ;
	if (!mini->tokens->content)
	{
		mini->error = INPUT_ERROR;
		return ;
	}
	i = mini_tablen(mini->env_copy);
	tmp = mini->tokens;
	while (tmp && !mini_is_intab(mini->sep, tmp->content, 0))
	{
		if (get_env(mini, tmp->content) != NULL)
			i--;
		tmp = tmp->next;
	}
	new_env = copy_tab(mini, i);
	if (!new_env)
		return ;
	mini_freetab(mini->env_copy);
	mini->env_copy = new_env;
}
