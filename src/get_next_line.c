/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:17:03 by irhett            #+#    #+#             */
/*   Updated: 2017/05/14 00:54:27 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char			*concat(char *str1, char *str2, int mall_1, int mall_2)
{
	int		len1;
	int		len2;
	char	*ans;

	len1 = 0;
	len2 = 0;
	while (str1[len1])
		len1++;
	while (str2[len2])
		len2++;
	ans = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ans)
		return (NULL);
	len1 = -1;
	len2 = -1;
	while (str1[++len1])
		ans[len1] = str1[len1];
	while (str2[++len2])
		ans[len1 + len2] = str2[len2];
	if (mall_1)
		free(str1);
	if (mall_2)
		free(str2);
	ans[len1 + len2] = '\0';
	return (ans);
}

int				scan(char *str, int newline)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == DELIM && newline)
			return (index);
		index++;
	}
	if (newline)
		return (-1);
	return (index);
}

int				copy(char *src, char **dst, char **stat, int fd)
{
	int		index;
	int		len;
	int		ret;

	ret = 0;
	len = 0;
	while ((src[len] != DELIM) && (src[len] != '\0'))
		len++;
	dst[0] = (char*)malloc(sizeof(char) * len + 1);
	index = 0;
	while ((src[index] != DELIM) && (src[index] != '\0'))
	{
		dst[0][index] = src[index];
		index++;
	}
	dst[0][index] = '\0';
	if (src[index] == DELIM)
	{
		ret = 1;
		stat[fd] = concat(&(src[++index]), "", 0, 0);
	}
	free(src);
	return (ret);
}

int				cleanup(char **stat, int fd, char *buff, char *ret)
{
	if (stat[fd])
		free(stat[fd]);
	free(buff);
	free(ret);
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*stat[1];
	int				br;
	char			*buffer;
	char			*ret;

	br = 1;
	if (fd < 0 || (line == NULL) || BUFF_SIZE <= 0)
		return (-1);
	if (stat[0] != NULL)
		ret = concat(stat[0], "", 1, 0);
	else
		ret = concat("", "", 0, 0);
	stat[0] = NULL;
	while ((scan(ret, 1) == -1) && br)
	{
		buffer = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		br = read(fd, buffer, BUFF_SIZE);
		if (br == -1)
			return (cleanup(stat, 0, buffer, ret));
		buffer[br] = '\0';
		ret = concat(ret, buffer, 1, 1);
	}
	if ((copy(ret, line, stat, 0) == 0) && (br == 0) && (scan(ret, 0) == 0))
		return (0);
	return (1);
}
