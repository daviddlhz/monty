#include "monty.h"

/**
* _swap - swaps the top two elements of the stack.
* @stack: struct of the doubly linked list
* @line_number: number of the line in the file.
*/

void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = tmp;
}

/**
* _add - dds the top two elements of the stack.
* @stack: struct of the doubly linked list
* @line_number: number of the line in the file.
*/

void _add(stack_t **stack, unsigned int line_number)
{
	int val1;
	int val2;
	int sum_val;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	val1 = (*stack)->n;
	val2 = (*stack)->next->n;
	sum_val = val1 + val2;

	_pop(stack, line_number);
	(*stack)->n = sum_val;
}
