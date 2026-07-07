#include <unistd.h>

// Skip spaces and tabs, return index of next non-whitespace char
int skip_whitespace(char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\t')
		++i;
	return (i);
}

// Get length of current word (stops at space, tab, or null terminator)
int word_length(char *s)
{
	int i = 0;

	while (s[i] && s[i] != ' ' && s[i] != '\t')
		++i;
	return (i);
}

// Print one word with proper spacing
int print_word(char *s, int i, int *is_first)
{
	int word_len;

	i = skip_whitespace(s, i);
	word_len = word_length(s + i);
	
	// Add space before word if not the first one
	if (!*is_first)
		write(1, " ", 1);
	
	// Print the word
	write(1, s + i, word_len);
	*is_first = 0;
	
	return (i + word_len);
}

// Print all words in string with normalized spacing
void print_all_words(char *s)
{
	int i = 0;
	int is_first = 1;

	i = skip_whitespace(s, i);
	while (s[i])
	{
		i = print_word(s, i, &is_first);
		i = skip_whitespace(s, i);
	}
}

int main(int ac, char **av)
{
	int i;
	int is_first;

	if (ac >= 2)
	{
		// Find start of first word
		i = skip_whitespace(av[1], 0);
		
		// Move to end of first word
		i += word_length(av[1] + i);
		
		// Print remaining words (everything after first word)
		print_all_words(av[1] + i);
		
		// Print the first word at the end
		is_first = 0;
		print_word(av[1], 0, &is_first);
	}
	
	write(1, "\n", 1);
	return (0);
}