/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:59:05 by romartin          #+#    #+#             */
/*   Updated: 2023/07/25 13:42:35 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

int	mini_pwd(void)
{
	char	args[1024];

	printf("%s\n", getcwd(args, 1024));
	return (EXIT_SUCCESS);
}
