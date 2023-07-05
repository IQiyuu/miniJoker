/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:50:26 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/05 13:40:11 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int	mini_cd(t_minijoker *mini)
{
	char	*path;
	char	*str;
	int		error;

	error = SUCCESS;
	if (!mini->tokens[mini->index + 1] 
		|| mini_strcmp(mini->tokens[mini->index++], "~", 0) == 0)
		chdir(get_env(mini, "HOME"));
	else if (chdir(mini->tokens[mini->index]) == -1)
	{
		path = getcwd(NULL, 0);
		str = mini_strjoin(path, "/");
		path = mini_strjoin(str, mini->tokens[mini->index]);
		free(str);
		if (access(path, X_OK) == 0)
			error = EXEC_FILE;
		else
			error = DIR_NOT_FOUND;
		free(path);
	}
	return (error);
}
