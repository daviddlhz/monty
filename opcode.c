#include "monty.h"

/**
 * _push - add in the stack
 * @stack: struct of the doubly linked list
 * @line_number: number of the line in the file.
 */

void _push(stack_t **stack, unsigned int line_number)
{

	stack_t *new;
	unsigned int num, i;

	for (i = 0; i < strlen(value); i++)
	{
		if (value[i] == '-')

		i++;

		if (!isdigit(value[i]))
		{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack_list(stack);
		exit(EXIT_FAILURE);

		}
	}

	num = atoi(value);
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new->next = *stack;
	new->prev = NULL;

	if (*stack)
	(*stack)->prev = new;
	new->n = num;
	*stack = new;
}

/**
 * _pall - print the stack
 * @stack: struct of the doubly linked list
 * @line_number: number of the line in the file.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;
	while (tmp != NULL)
	{
	printf("%d\n", tmp->n);
	tmp = tmp->next;
	}
}
/**
 * _pint - prints the value at the top of the stack
 * @stack: struct of the doubly linked list
 * @line_number: number of the line in the file.
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", tmp->n);
}
/**
 * _pop - remove a value to the stack
 * @stack: struct of the doubly linked list
 * @line_number: number of the line in the file.
 */
void _pop(stack_t **stack, unsigned int line_number)

{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free_stack_list(stack);
	exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (tmp->next != NULL)
	(*stack)->prev = NULL;
	else
	*stack = NULL;
	free(tmp);
}
/**
 * _nop - doesn’t do anything
 * @stack: struct of the doubly linked list
 * @line_number: number of the line in the file.
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
