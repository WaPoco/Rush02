/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasili <vasili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:49:02 by vasili            #+#    #+#             */
/*   Updated: 2024/11/03 12:51:19 by vasili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	count_digits(int number)
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

void	chunk_word(int chunk, struct Dictionary *dict, int len_chunk)
{	
	int	result;

	if (chunk == 0)
		return ;
	if (len_chunk == 3)
	{
		printf("%s ", get_word_number(chunk / 100, dict));
		result = (chunk / 100) * 100;
		printf("%s ", get_word_number(100, dict));
		chunk -= result;
		len_chunk--;
	}
	if (len_chunk == 2)
	{
		if (get_word_number(chunk, dict) != NULL && chunk != 0)
		{
			printf("%s ", get_word_number(chunk, dict));
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

void	make_chunks(int number, struct Dictionary *dict)
{
	int	len;
	int	i;
	int	chunk;

	i = 0;
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
