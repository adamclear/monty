#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number from main
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		arg = "error";
		return;
	}
	current = (*stack)->prev;
	free(*stack);
	*stack = current;
	if (!*stack)
		return;
	(*stack)->next = NULL;
return;
}
