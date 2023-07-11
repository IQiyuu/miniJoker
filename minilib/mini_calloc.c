/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqiyu <iqiyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:12:10 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/11 14:14:16 by iqiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void    *mini_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(count * size);
	if (!ptr)
		return (NULL);
	mini_bzero(ptr, count);
	return (ptr);
}
