/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:41:59 by romartin          #+#    #+#             */
/*   Updated: 2023/07/04 12:10:35 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/*
PAS FINI
*/
int mini_unset(t_miniJoker *mini)
{
	char **new_env;
	char **inputs;
	char *var;
	int i;

	i = 0;
	if (!mini->tokens[1])
		return (EXIT_SUCCESS);
	inputs = mini_ft_split(mini->tokens[1], '='); //malloc
	i = mini_tablen(mini->env_copy);
	new_env = (char **)malloc(sizeof(char *) * (i + 1)); //malloc
	i = 0;
	while (mini->env_copy[i])
	{
		var = mini_cut_to(mini->env_copy[i], '=');
		if (mini_strcmp(var, mini->tokens[1], 0) != 0)
		{
			new_env[i] = mini_strdup(mini->env_copy[i]);
			if (!new_env[i])
			{
				printf("malloc faillure\n");
				mini_freetab(new_env);
				return (EXIT_SUCCESS);
			}
		}
		free(var);
		i++;
	}
	if (getEnv(mini, inputs[0]) != NULL)
		i--;
	new_env[i] = NULL;
	mini_freetab(mini->env_copy);
	mini->env_copy = new_env;
	mini_freetab(inputs);
	return (EXIT_SUCCESS);
}