#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to stack
 * @line_count: line count from main
 * Return: void
 */
void pint(stack_t **stack, unsigned long int line_count);
{
	if (!stack)
	{
		printf("L%ld: can't pint, stack empty\n", line_count);

	}
}
