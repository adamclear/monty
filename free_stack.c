#include "monty.h"
/**
 * free_stack - frees the stack
 * @stack: the stack to be freed
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current;
	stack_t *next;

	if (stack)
	{
		current = stack;
		while (current)
		{
			next = current->prev;
			free(current);
			current = next;
		}
	}
return;
}
