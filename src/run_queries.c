/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_queries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 23:35:42 by irhett            #+#    #+#             */
/*   Updated: 2017/05/14 23:39:25 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		run_queries(t_table *t)
{
	int		ret;
	char	*query;
	char	*value;

	while ((ret = get_next_line(0, &query)) > 0)
	{
		value = get_value(t, query);
		if (value)
		{
			hr_putstr(value);
			write(1, "\n", 1);
		}
		else
		{
			hr_putstr(query);
			hr_putstr(": Not found.\n");
		}
	}
	if (ret < 0)
		return (1);
	return (0);
}
