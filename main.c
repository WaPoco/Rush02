#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct Dictionary {
	int		number;
	char	word[20];
};

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
		return (" ");
	return (dict[i].word);
}

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
		if (get_word_number(chunk, dict) != " " && chunk != 0)
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
	make_chunks(789, eng);
	free(eng);
	return (0);
}