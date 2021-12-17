#include "monty.h"
/**
 * pall - prints all the values in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number from main
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;

	if (stack)
	{
		current = *stack;
		while (current)
		{
			printf("%d\n", current->n);
			current = current->prev;
		}
	}
return;
}
