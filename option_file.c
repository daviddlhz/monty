#include "monty.h"

/**
 * option_file - This function is the controller in the instructions to stack
 * @optn: option of instrucctions
 * @line: is the line instruction
 * @list: is the struct stack to utilizar
 * @content: is the content in the line
 * Return: void
 */

void option_file(char *optn, unsigned int line, stack_t **list, char *content)
{
	int i = 0;
	instruction_t op_option[] = {
		{"push", _push},
		{"pall", _pall},
		{"pop", _pop},
		{"pint", _pint},
		{"nop", _nop},
		{NULL, NULL}
	};

	while (op_option[i].opcode != NULL)
	{
		if (strcmp(op_option[i].opcode, optn) == 0)
		{
			op_option[i].f(list, line);
			return;
		}
		i++;
	}
	if (op_option[i].opcode == NULL)
	{
		printf("L%d: unknown instruction %s\n", line, optn);
		free_stack_list(list);
		free(content);
		exit(EXIT_FAILURE);
	}
}
