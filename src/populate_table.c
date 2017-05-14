/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 20:57:58 by irhett            #+#    #+#             */
/*   Updated: 2017/05/14 00:44:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int			populate_table(t_table *t)
{
	t_entry	*temp;
	char	*key;
	char	*val;
	int		ret;
	int		going;

	if (!t)
		return (-1);
	going = 1;
	while (going)
	{
		if ((ret = get_next_line(0, &key)) <= 0)
			return (1);
		if (*key)
		{
			if ((ret = get_next_line(0, &val)) <= 0)
				return (1);
			if (!*val)
				return (1);
			temp = init_entry(key, val);
			add_entry(t, temp);
		}
		else
			going = 0;
	}
	return (0);
}
