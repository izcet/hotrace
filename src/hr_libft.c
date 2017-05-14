/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hr_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 20:29:08 by irhett            #+#    #+#             */
/*   Updated: 2017/05/14 00:44:45 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

unsigned int	hr_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (str)
	{
		while (*str++)
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
			*(char*)ptr = 0;
			ptr++;
			size--;
		}
	}
}

char			hr_strcmp(char *s1, char *s2)
{
	int    result;
	size_t idx;

	__asm__("mov $-16, %1\n"
			"cmploop: add $16, %1\n"
			"movdqu (%1,%2), %%xmm1\n"
			"movdqu (%1,%3), %%xmm0\n"
			"pcmpistri $24, %%xmm0, %%xmm1\n"
			"jnbe cmploop\n"
			"jnc equal\n"
			"add %%rcx, %1\n"
			"mov $1, %0\n"
			"jmp done\n"
			"equal: xor %0, %0\n"
			"done:nop"
			: "=r"(result), "+r"(idx)
			: "r"(s1), "r"(s2)
			: "rcx", "cc", "xmm0", "xmm1");
	if (result)
		return (s2[idx] - s1[idx]);
	return (0);
}
