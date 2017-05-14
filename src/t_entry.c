/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_entry.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:01:05 by irhett            #+#    #+#             */
/*   Updated: 2017/05/14 00:45:24 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_entry		*del_entry(t_entry *e)
{
	t_entry	*temp;

	if (e)
	{
		if (e->key)
			free(e->key);
		if (e->value)
			free(e->value);
		temp = e->next;
		free(e);
		return (temp);
	}
	else
		hr_putstr("Error: Entry being freed was not allocated.");
	return (NULL);

}

void		del_entry_line(t_entry *e)
{
	while (e)
		e = del_entry(e);
}

t_entry		*init_entry(char *key, char *value)
{
	t_entry			*e;

	e = (t_entry*)malloc(sizeof(t_entry));
	if (!e)
		return (NULL);
	e->key = key;
	e->value = value;
	return (e);
}
