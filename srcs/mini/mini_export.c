/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:24:56 by romartin          #+#    #+#             */
/*   Updated: 2023/07/04 12:46:06 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

static char	**copy_tab(t_minijoker *mini, char **str, int i)
{
	char	**tmp;
	char	*var;

	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (mini->env_copy[i])
	{
		var = mini_cut_to(mini->env_copy[i], '=');
		if (mini_strcmp(var, str[0], 0) == 0)
			tmp[i] = mini_strdup(mini->tokens[1]);
		else
			tmp[i] = mini_strdup(mini->env_copy[i]);
		free(var);
		i++;
	}
	if (get_env(mini, str[0]) == NULL)
		tmp[i++] = mini_strdup(mini->tokens[1]);
	tmp[i] = NULL;
	return (tmp);
}

/* Gestion de la fonction export  */
/* prend mini en argument pour les token */
/* renvoie 1 si elle réussi */
int	mini_export(t_minijoker *mini)
{
	char	**str;
	char	**tmp;
	int		i;

	if (!mini->tokens[1])
	{
		mini_env(mini);
		return (EXIT_SUCCESS);
	}
	str = mini_ft_split(mini->tokens[1], '=');
	if (!str[0] || !str[1])
	{
		mini_freetab(str);
		return (EXIT_FAILLURE);
	}
	i = mini_tablen(mini->env_copy);
	if (get_env(mini, str[0]) == NULL)
		i++;
	tmp = copy_tab(mini, str, i);
	mini_freetab(mini->env_copy);
	mini->env_copy = tmp;
	mini_freetab(str);
	return (EXIT_SUCCESS);
}