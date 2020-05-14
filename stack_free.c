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
