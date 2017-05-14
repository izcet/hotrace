/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:43:42 by irhett            #+#    #+#             */
/*   Updated: 2017/05/14 01:06:18 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# define TABLE_SIZE	500 
# define BUFF_SIZE	64
# define DELIM		'\n'

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_entry
{
	char			*key;
	char			*value;
	struct s_entry	*next;
}					t_entry;

typedef struct		s_table
{
	unsigned int	size;
	t_entry			**entries;
}					t_table;

unsigned int		hash_key(char *key, unsigned int size);

t_table				*init_table(unsigned int size);
t_entry				*init_entry(char *key, char *value);

// right now none of these are used to save execution time
// to improve stability, portability, and use in other expansions
// uncomment the section included in main
// do not uncomment for the submission of this project as they will impact time
void				del_table(t_table *t);
void				del_entry_line(t_entry *e);
t_entry				*del_entry(t_entry *e);

// return 0 on success, !0 on error
int					populate_table(t_table *t);
int					run_queries(t_table *t);

void				add_entry(t_table *t, t_entry *e);
char				*get_value(t_table *t, char *query);

// hr for hot_race
// these files can be found in hr_libft.c
void				hr_putstr(char *str);
unsigned int		hr_strlen(char *str);
void				hr_bzero(void *ptr, unsigned int size);
char				hr_strcmp(char *s1, char *s2);

int					get_next_line(int fd, char **line);

#endif
