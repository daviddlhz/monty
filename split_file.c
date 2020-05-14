#include "monty.h"
char *value;
/**
 * split_file - cut the words in string with strtok.
 * @content_file: is the content in the file.
 *
 * Return: Nothing.
 */
void split_file(char *content_file)
{
	int i = 0;
	stack_t *stack_list = NULL;
	unsigned int line_ins;
	char *content_split[200];

	content_file = strtok(content_file, DELIMITERS);

	while (content_file != NULL)
	{
		content_split[i] = content_file;
		content_file = strtok(NULL, DELIMITERS);
		i++;
	}

	content_split[i] = '\0';
	i = 0;

	while (content_split[i] != NULL)
	{
		if (strcmp(content_split[i], "push") == 0)
		{
			line_ins++;
			value = content_split[i + 1];
			option_file(content_split[i], line_ins, &stack_list);
		}
		if (strcmp(content_split[i], "pall") == 0)
		{
			line_ins++;
			option_file(content_split[i], line_ins, &stack_list);
		}

		i++;
	}
}
