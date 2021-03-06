#include "monty.h"

/**
 * split_file - cut the words in string with strtok.
 * @content_file: is the content in the file.
 * @stack_list: is the stack.
 * @line: is the line of instruction
 * Return: Nothing.
 */
void split_file(char *content_file, stack_t **stack_list, unsigned int line)
{
	int i = 0;
	char *content_cut = NULL;
	char *content_split[200];

	content_cut = strtok(content_file, DELIMITERS);
	while (content_cut != NULL)
	{
	content_split[i] = content_cut;
	content_cut = strtok(NULL, DELIMITERS);
	i++;

	}
	content_split[i] = '\0';
	i = 0;

	if (content_split[i] != NULL)
	{
		value = content_split[i + 1];
		option_file(content_split[i], line, stack_list, content_file);
	}
}
