#include "monty.h"
/**
 * getfunction - finds a match for the provided command and associates it
 *               with a function name.
 * @stack: Pointer to the stack
 * @cmd: The current token from main
 * @lncnt: The current line count
 * Return: the approprate function, or NULL if not found
 */
void getfunction(stack_t **stack, char *cmd, unsigned int lncnt)
{
	int x;
	instruction_t function[] = OPCODES;

	if (cmd == NULL)
		return;
	for (x = 0; function[x].opcode; x++)
	{
		if (strcmp(function[x].opcode, cmd) == 0)
		{
			function[x].f(stack, lncnt);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lncnt, cmd);
}
