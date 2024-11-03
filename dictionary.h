/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasili <vasili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:55:55 by vasili            #+#    #+#             */
/*   Updated: 2024/11/03 22:40:53 by vasili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
#define DICTIONARY_H


struct Dictionary {
	int		number;
	char	word[20];
};
int	count_lines(char *s);
void	parseDict(char *s, struct Dictionary *dict, int lines);
char	*get_word_number(long number, struct Dictionary *dict);
char	*file_str(char *pathDict);
struct dictionary	*str_Dict(char *buffer);

#endif