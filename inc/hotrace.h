/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:43:42 by irhett            #+#    #+#             */
/*   Updated: 2017/05/13 21:55:43 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# define TABLE_SIZE	5000000
# define BUFF_SIZE	64000

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_entry
{
	char			*key;
	char			*value;
	sruct s_entry	*next;
}					t_entry;

typedef struct		s_table
{
	unsigned int	size;
	t_entry			**entries;
}					t_table;

unsigned int		hash_key(char *key, unsigned int size);

t_table				*init_table(unsigned int size);
t_entry				*init_entry(char *key, char *value);
void				del_table(t_table *t);
void				del_entry_line(t_entry *e);
t_entry				*del_entry(t_entry *e);

int					read_input(t_table *table, int is_query);
int					populate_table(t_table *t, char **excess);
//int					run_queries(t_table *t, char **excess);

void				add_entry(t_table *t, t_entry *e);

void				hr_putstr(char *str);
unsigned int		hr_strlen(char *str);
void				hr_bzero(void *ptr, unsigned int size);
//char				hr_strcmp(char *s1, char *s2);

int					get_next_line(char **line);
char				*gnl_concat(char *s1, char *s2, int a, int b);

#endif
