/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 21:29:18 by irhett            #+#    #+#             */
/*   Updated: 2017/05/13 21:53:05 by irhett           ###   ########.fr       */
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
	while (c = *str++)
		hash = c + (hash << 6) + (hash << 16) - hash;
	return (hash % size);
}
