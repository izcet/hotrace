/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_table.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:01:05 by irhett            #+#    #+#             */
/*   Updated: 2017/05/14 00:45:27 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void		del_table(t_table *t)
{
	if (t)
	{
		if (t->entries)
		{
			while (t->size > 0)
			{
				t->size--;
				if (t->entries[t->size])
					del_entry_line(t->entries[t->size]);
			}
			free(t->entries);
		}
		free(t);
	}
	else
		hr_putstr("Error: Table being freed was not allocated.");

}

t_table		*init_table(unsigned int size)
{
	t_table			*t;
	unsigned int	i;

	i = 0;
	t = (t_table*)malloc(sizeof(t_table));
	if (!t)
		return (NULL);
	t->size = size;
	t->entries = (t_entry**)malloc(sizeof(t_entry*) * size);
	if (!(t->entries))
	{
		free(t);
		return (NULL);
	}
	hr_bzero(t->entries, size);
	return (t);
}
