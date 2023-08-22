/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokendelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:46:22 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/22 15:34:46 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	mini_tokendelone(t_token **tokens)
{
	t_token	*tmp;

	if (tokens)
	{
		if (*tokens)
		{
			tmp = *tokens;
			if ((tmp)->prev)
			{
				*tokens = (*tokens)->prev;
				(tmp)->prev->next = (tmp)->next;
			}
			if ((tmp)->next)
			{
				*tokens = (*tokens)->next;
				(tmp)->next->prev = (tmp)->prev;
			}
			if ((tmp)->content)
				free((tmp)->content);
			free(tmp);
		}
	}
}
