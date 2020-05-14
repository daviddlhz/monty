#include "monty.h"

/**
 * option_file - This function is the controller in the instructions to stack
 * @option: option of instrucctions
 * @line_ins: is the line instruction
 * @stack_list: is the struct stack to utilizar
 * Return: void
 */

void option_file(char *option, unsigned int line_ins, stack_t **stack_list)
{
	int i = 0;
	instruction_t op_option[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	while (op_option[i].opcode != NULL)
	{
		if (strcmp(op_option[i].opcode, option) == 0)
		{
			op_option[i].f(stack_list, line_ins);
			return;
		}
		i++;
	}
	if (op_option[i].opcode == NULL)
	{
		printf("L%d: unknown instruction %s\n", line_ins, option);
		exit(EXIT_FAILURE);
	}
}
