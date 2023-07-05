/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:36:25 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/05 13:45:58 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void	exec_loop(char *str, t_minijoker *mini)
{
	int	end;
	int	n;

	n = 0;
	(void)str;
	end = mini_exec(mini);
	if (end == UNKNOW_COMMAND)
		end = true_exec(mini);
	while (mini->tokens[mini->index] && end == UNKNOW_COMMAND)
	{
		if (!is_mini_func(mini))
			end = true_exec(mini);
		mini->index++;
	}
}

int	true_exec(t_minijoker *mini)
{
	if (!mini->tokens[mini->index])
		return (1);
	printf("%s: command not found\n", mini->tokens[mini->index]);
	return (0);
}
