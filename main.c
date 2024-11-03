/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasili <vasili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:48:59 by vasili            #+#    #+#             */
/*   Updated: 2024/11/03 12:48:31 by vasili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
#include "dictionary.h"

int main(int arg0, char **args) {

	struct Dictionary *eng;
	int	 	fd;
	char	buffer[691];
	int		bytesRead;
	int		lines;
	int		i;

	lines = 0;
	i = 0;
	fd = open("en.dict", O_RDONLY);
	bytesRead = read(fd, buffer, 690);
	buffer[bytesRead] = '\0';
	lines = count_lines(buffer);
	eng = malloc(lines * sizeof(struct Dictionary));
	eng = parseDict(buffer, bytesRead, lines);
	make_chunks(atol(args[1]), eng);
	free(eng);
	return (0);
}