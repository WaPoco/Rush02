/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasili <vasili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:49:05 by vasili            #+#    #+#             */
/*   Updated: 2024/11/03 22:40:53 by vasili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>


int	count_lines(char *s)
{
	int	lines;

	lines = 0;
	while(*s)
	{
		if (*s == '\n')
			lines += 1;
		s++;
	}
	return (lines + 1);
}

void	parseDict(char *s, struct Dictionary *dict, int lines)
{
	int	i;
//	int	number;
	int	k;

	i = 0;
	while (i < lines)
	{
/*		number = 0;
		while ('0' <= *s && *s <= '9')
		{
			number = 10*number + (*s - '0');
			s++;
		}
*/
		dict[i].number = atol(s);
		while (*s < 'a' || *s > 'z')
			s++;
		k = 0;
		while (*s != '\n' && *s)
		{
			dict[i].word[k] = *s;
			s++;
			k++;
		}
		dict[i].word[k] = '\0';
		i++;
		s++;
	}
	return (dict);
}

char	*get_word_number(long number, struct Dictionary *dict)
{
	int	i;

	i = 0;
	while (dict[i].number != number && i != 40)
		i++;
	if (i == 40)
		return (NULL);
	return (dict[i].word);
}

char	*file_str(char *pathDict)
{
	int	 	fd;
	char	*buffer;
	int		bytesRead;
	int		bytes_buffer;

	bytes_buffer = 0;
	fd = open(pathDict, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", sizeof("Dict Error\n") / sizeof(char));
		return ;
	}
	bytes_buffer = lseek(fd, 0, SEEK_END);
	bytesRead = read(fd, buffer, bytes_buffer - 1);
	if (bytes_buffer == -1)
	{
		write(1, "Dict Error\n", sizeof("Dict Error\n") / sizeof(char));
		return ;	
	}
	buffer[bytesRead] = '\0';
	return (buffer);
}

struct dictionary *str_Dict(char *buffer)
{
	int		lines;
	int		bytes_buffer;
	struct	Dictionary *dict;

	lines = 0;
	bytes_buffer = 0;
	lines = count_lines(buffer);
	dict = malloc(lines * sizeof(struct Dictionary));
	if (dict == NULL)
	{
		write(1, "Dict Error\n", sizeof("Dict Error\n") / sizeof(char));
		return ;
	}
	return (dict);
}