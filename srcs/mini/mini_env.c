/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:35:56 by romartin          #+#    #+#             */
/*   Updated: 2023/07/31 15:44:05 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

char	*get_env(t_minijoker *mini, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (mini->env_copy[i])
	{
		tmp = mini_cut_to(mini->env_copy[i++], '=');
		if (!tmp)
			return (NULL);
		if (mini_strcmp(tmp, str, 0) == 0)
		{
			free(tmp);
			return (&mini->env_copy[i - 1]
				[mini_charfind(mini->env_copy[i - 1], '=') + 1]);
		}
		free(tmp);
	}
	return (NULL);
}

int	mini_env(t_minijoker *mini)
{
	int	i;

	i = 0;
	while (mini->env_copy[i])
	{
		printf("%s\n", mini->env_copy[i]);
		i++;
	}
	mini->tokens = mini->tokens->next;
	return (SUCCESS);
}
