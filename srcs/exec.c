/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:36:25 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/07 10:56:15 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int	exec_loop(t_minijoker *mini)
{
	int	error;

	error = mini_exec(mini);
	if (error == UNKNOW_COMMAND)
		error = true_exec(mini);
	while (mini->tokens && error == UNKNOW_COMMAND)
	{
		if (!is_mini_func(mini))
			error = true_exec(mini);
		mini->tokens = mini->tokens->next;
	}
	//error_manager(error);
	return (error);
}

int	true_exec(t_minijoker *mini)
{
	if (!mini->tokens->content)
		return (1);
	printf("%s: command not found\n", mini->tokens->content);
	return (0);
}
