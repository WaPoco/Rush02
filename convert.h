#ifndef CONVERT_H
#define CONVERT_H

#include "dictionary.h"

int	count_digits(int number);
int	ten_to_power(int power);
void	chunk_word(int chunk, struct Dictionary *dict, int len_chunk);
void	make_chunks(int number, struct Dictionary *dict);

#endif