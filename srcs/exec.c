/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:36:25 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/08 16:54:34 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int	exec_loop(t_minijoker *mini)
{
	mini_exec(mini);
	if (mini->error == UNKNOW_COMMAND)
		mini->error = true_exec(mini);
	while (mini->tokens && mini->error == UNKNOW_COMMAND)
	{
		if (!is_mini_func(mini->tokens->content))
			mini->error = true_exec(mini);
		mini->tokens = mini->tokens->next;
	}
	//mini->error_manager(mini->error);
	return (mini->error);
}

int	true_exec(t_minijoker *mini)
{
	if (!mini->tokens->content)
		return (1);
	printf("%s: command not found\n", mini->tokens->content);
	return (0);
}
