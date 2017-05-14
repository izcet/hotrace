/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:50:02 by irhett            #+#    #+#             */
/*   Updated: 2017/05/14 00:44:47 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		main(void)
{
	t_table		*t;

	t = init_table(TABLE_SIZE);
	if (!t)
		return (1);
	if (populate_table(t))
		return (1);
	if (run_queries(t))
		return (1);
	//del_table(t);
	return (0);
}
