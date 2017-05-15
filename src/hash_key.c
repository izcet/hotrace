/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 21:29:18 by irhett            #+#    #+#             */
/*   Updated: 2017/05/14 23:33:11 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/*
 **	algorithm used: sdbm
 **	www.cse.yorku.ca/~oz/hash.html
 */

unsigned int	hash_key(char *str, unsigned int size)
{
	unsigned int	hash;
	char			c;

	hash = 0;
	if (str)
	{
		while ((c = *str++))
			hash = c + (hash << 6) + (hash << 16) - hash;
	}
	else
		hr_putstr("NULL passed to hashkey\n");
	return (hash % size);
}
