/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:30:32 by irhett            #+#    #+#             */
/*   Updated: 2017/05/13 20:57:53 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		read_input(t_table *table, int is_query)
{
	static char		*excess;
	int				br;

	br = 1;
	if (BUFF_SIZE <= 0 || !table)
		return (-1);
	if (is_query)
		return (populate_table(table));
	return (run_queries(table));
}
