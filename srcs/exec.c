/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:36:25 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/04 16:42:37 by dgoubin          ###   ########.fr       */
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
		end = true_exec(mini, n);
	while (mini->tokens[n] && end == UNKNOW_COMMAND)
		if (!is_mini_func(mini, n))
			end = true_exec(mini, n++);
}

int	true_exec(t_minijoker *mini, int i)
{
	if (!mini->tokens[i])
		return (1);
	printf("%s: command not found\n", mini->tokens[i]);
	return (0);
}
