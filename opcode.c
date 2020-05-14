#include "monty.h"
 
/**
 * free_stack_list - free a stack.
 *
 *@stack_list: the list to delete.
 */
 
void free_stack_list(stack_t **stack_list)
{
    stack_t *tmp;
 
    if (*stack_list == NULL)
    {
        return;
    }
    while (*stack_list != NULL)
    {
        tmp = *stack_list;
        if ((*stack_list)->next == NULL)
        {
            free(tmp);
            *stack_list = NULL;
            break;
        }
        *stack_list = (*stack_list)->next;
        (*stack_list)->prev = NULL;
        free(tmp);
    }
}
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
        write(2, "Error: malloc failed\n", 21);
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
 
#include "monty.h"
 
 
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
