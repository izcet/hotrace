/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 20:29:08 by irhett            #+#    #+#             */
/*   Updated: 2017/05/13 20:34:10 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

unsigned int	hr_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (str)
	{
		while (*str)
			i++;
	}
	return (i);
}

void			hr_putstr(char *str)
{
	write(1, str, hr_strlen(str));
}

void			hr_bzero(void *ptr, unsigned int size)
{
	if (ptr)
	{
		while (size)
		{
			*ptr = 0;
			ptr++;
			size--;
		}
	}
}

char			hr_strcmp(char *s1, char *s2)
{
	return (0);
}
