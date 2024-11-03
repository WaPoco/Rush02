/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasili <vasili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:48:59 by vasili            #+#    #+#             */
/*   Updated: 2024/11/03 22:40:53 by vasili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
#include "dictionary.h"

int main(int arg0, char **args)
{
	char	*strDict;
	struct Dictionary *dict;
	
	strDict = file_str("en.dict");
	dict = str_Dict(strDict);
	parseDict(strDict, dict, count_lines(strDict));
	split_number_chunks(atol(args[1]), dict);
	free(dict);
	return (0);
}