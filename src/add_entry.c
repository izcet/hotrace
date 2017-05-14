/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 21:24:07 by irhett            #+#    #+#             */
/*   Updated: 2017/05/14 00:44:32 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	add_entry(t_table *t, t_entry *e)
{
	unsigned int	i;

	if (t && e && e->key && t->entries)
	{
		i = hash_key(e->key, t->size);
		if (t->entries[i])
		{
//			hr_putstr("COLLISION!\n"); // remove later
			e->next = t->entries[i];
		}
		t->entries[i] = e;
	}
	else
		hr_putstr("NULL passed to add_entry!\n");
}
