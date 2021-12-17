#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to stack
 * @line_number: line count from main
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	if (current)
	{
		printf("%d\n", current->n);
		return;
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		arg = "error";
		return;
	}
}
