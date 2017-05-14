/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 23:53:30 by irhett            #+#    #+#             */
/*   Updated: 2017/05/14 00:44:41 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*get_value(t_table *t, char *query)
{
	t_entry	*e;

	e = t->entries[hash_key(query, t->size)];
	while (e)
	{
		if (hr_strcmp(query, e->key) == 0)
			return (e->value);
		e = e->next;
	}
	return (NULL);
}
