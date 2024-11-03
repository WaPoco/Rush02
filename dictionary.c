/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasili <vasili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:49:05 by vasili            #+#    #+#             */
/*   Updated: 2024/11/03 12:47:06 by vasili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

struct Dictionary *parseDict(char *s, int max, int lines)
{
	struct Dictionary *dict;

	int	i;
	int	number;
	int	k;

	i = 0;
	dict = malloc(lines * sizeof(struct Dictionary));
	while (i < lines)
	{
		number = 0;
		while ('0' <= *s && *s <= '9')
		{
			number = 10*number + (*s - '0');
			s++;
		}
		dict[i].number = number;
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
	return dict;
}

char	*get_word_number(int number, struct Dictionary *dict)
{
	int	i;

	i = 0;
	while (dict[i].number != number && i != 40)
		i++;
	if (i == 40)
		return (NULL);
	return (dict[i].word);
}
