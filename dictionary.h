#ifndef DICTIONARY_H
#define DICTIONARY_H


struct Dictionary {
	int		number;
	char	word[20];
};
int	count_lines(char *s);
struct Dictionary	*parseDict(char *s, int max, int lines);
char	*get_word_number(int number, struct Dictionary *dict);

#endif