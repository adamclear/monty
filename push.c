#include "monty.h"
/**
 * push - adds a node to the stack
 * @stack: Pointer to the stack
 * @lncnt: The line count from main
 * @arg: Argument passed with function
 */
void push(stack_t **stack, unsigned int line_count)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (!newnode)
	{
		free(newnode);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if ((isdigit(arg)) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}
	newnode->n = arg;
	newnode->prev = *stack;
	*stack = newnode;
	free(newnode);
return;
}
