#include "monty.h"
/**
 * main - parses a monty file and executes the commands given
 * @argc: number of arguments
 * @argv: array of arguments passed
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
	size_t buffsize = 1024;
	char *buffer = malloc(buffsize * sizeof(char));
	int linecount = 0;
	ssize_t linesize;
	FILE *file;
	char *command = NULL;
	stack_t *stack = NULL;
	int exitstatus = EXIT_SUCCESS;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	linesize = getline(&buffer, &buffsize, file);
	while (linesize >= 0)
	{
		linecount++;
		command = strtok(buffer, " \t\n");
		arg = strtok(NULL, " \t\n");
		if (arg == NULL)
			arg = "notdigit";
		getfunction(&stack, command, linecount);
		if (strcmp(arg, "error") == 0)
		{
			exitstatus = EXIT_FAILURE;
			break;
		}
		linesize = getline(&buffer, &buffsize, file);
	}
	free(buffer);
	free_stack(&stack);
	fclose(file);
	exit(exitstatus);
}
