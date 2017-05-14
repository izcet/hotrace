/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:50:02 by irhett            #+#    #+#             */
/*   Updated: 2017/05/13 21:07:25 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		main(void)
{
	int			ret;
	t_table		*t;

	t = init_table(TABLE_SIZE);
	if (!t)
		return (1);
	while ((ret = read_input(t, 0)) > 0)
		;
	if (ret < 0)
		exit(1);
	while ((ret = read_input(t, 1)) > 0)
		;
	if (ret < 0)
		exit (1);
	return (0);
}
