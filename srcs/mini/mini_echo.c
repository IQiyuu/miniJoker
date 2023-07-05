/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:43:06 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/04 16:36:03 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* Gestion de la fonction echo */
/* prend mini en argument pour les token */
/* renvoie 1 si elle réussi */
int	mini_echo(t_minijoker *mini)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (mini->tokens[i])
	{
		j = 0;
		if (mini->tokens[i][0] == '$')
		{
			if (get_env(mini, &mini->tokens[i][1]) != NULL)
				printf("%s", get_env(mini, &mini->tokens[i][1]));
		}
		else if (!mini_is_intab(mini->sep, mini->tokens[i])
			&& mini_strcmp(mini->tokens[i], "-n", 0) != 0)
		{
			printf("%s", mini->tokens[i]);
			if (mini->tokens[i + 1])
				printf(" ");
		}
		i++;
	}
	if (mini_strcmp(mini->tokens[1], "-n", 0) != 0)
		printf("\n");
	return (SUCCESS);
}
