/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqiyu <iqiyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:08:27 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/11 14:13:03 by iqiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

static int  mini_abs(int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

static void mini_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = mini_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

char    *mini_itoa(int n)
{
	char	*str;
	int		is_neg;
	size_t	length;

	is_neg = (n < 0);
	if (!(str = mini_calloc(11 + is_neg, sizeof(*str))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + mini_abs(n % 10);
		n = (n / 10);
	}
	if (is_neg)
		str[length] = '-';
	mini_strrev(str);
	return (str);
}
