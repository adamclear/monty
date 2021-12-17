#include "monty.h"
/**
 * swap - swaps the top two nodes of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number from main
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int x, y;
	stack_t *current;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		arg = "error";
		return;
	}
	current = *stack;
	x = current->n;
	current = current->prev;
	if (!current)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		arg = "error";
		return;
	}
	y = current->n;
	current->n = x;
	current = current->next;
	current->n = y;
return;
}
