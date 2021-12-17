#include "monty.h"

/**
 * add - adds the top two elements of the stack. The result is stored in
 * the second element of the stack, and the top element is removed.
 * @stack: pointer to head of stack
 * @line_number: line number from main
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int x, y;

	if(!*stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		arg = "error";
		return;
	}
	current = *stack;
	x = current->n;
	current = current->prev;
	if (!current)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		arg = "error";
		return;
	}
	y = current->n;
	current->n = (x + y);
	*stack = current;
	current = current->next;
	/*pop(*current, line_number);*/
	free(current);
	return;
}
