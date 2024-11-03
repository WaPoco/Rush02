/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasili <vasili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:49:02 by vasili            #+#    #+#             */
/*   Updated: 2024/11/03 22:40:53 by vasili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	count_digits(long number)
{
	int	digit;

	if (number == 0)
		return (1);
	digit = 0;
	while (number > 0)
	{
		number /= 10;
		digit++;
	}
	return (digit);
}

int	ten_to_power(int power)
{
	int	i;
	int	ten;

	i = 0;
	ten = 1;
	while (i < power)
	{
		ten *= 10;
		i++;
	}
	return (ten);
}

int str_len(char *s)
{
	int len;
	
	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	chunk_word(long chunk, struct Dictionary *dict, int len_chunk)
{	
	long	result;
	char	*word;

	if (chunk == 0)
		return ;
	if (len_chunk == 3)
	{
		write(1, get_word_number(chunk / 100, dict), str_len(get_word_number(chunk / 100, dict)));
		result = (chunk / 100) * 100;
		write(1, word, str_len(get_word_number(100, dict)));
		chunk -= result;
		len_chunk--;
	}
	if (len_chunk == 2)
	{
		if (get_word_number(chunk, dict) != NULL && chunk != 0)
		{
			write(1, get_word_number(chunk, dict), str_len(get_word_number(chunk, dict)));
			return ;
		}
		result = (chunk / 10) * 10;
		if (result != 0)
			printf("%s ", get_word_number(result, dict));
		chunk -= result;
		len_chunk--;
	}
	if (len_chunk == 1 && chunk != 0)
		printf("%s ", get_word_number(chunk, dict));
}

void	split_number_chunks(long number, struct Dictionary *dict)
{
	int	len;
	int chunk;
    
    chunk = 1;
	len = count_digits(number);
	if (number == 0)
	{
		printf("%s ", get_word_number(0, dict));
		return ;
	}
	while (len > 0)
	{
		if (len % 3 == 0)
			len -= 3;
		else
			len -= len % 3;
		chunk = number / ten_to_power(len);
	    chunk_word(chunk, dict, count_digits(chunk));
		if (len > 0 && number != 0)
			printf("%s ", get_word_number(ten_to_power(len), dict));
		number -=  chunk * ten_to_power(len);
	}
}
