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
	ssize_t linesize;
	FILE *file;
	char *command = NULL;
	stack_t *stack = NULL;
	int exitstatus = EXIT_SUCCESS, linecount = 1;

	if (!buffer)
	{
		free(buffer), fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"),	exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	linesize = getline(&buffer, &buffsize, file);
	while (linesize >= 0)
	{
		command = strtok(buffer, " \t\n\r");
		arg = strtok(NULL, " \t\n\r");
		if (arg == NULL)
			arg = "notdigit";
		getfunction(&stack, command, linecount);
		if (strcmp(arg, "error") == 0)
		{
			exitstatus = EXIT_FAILURE;
			break;
		}
		linesize = getline(&buffer, &buffsize, file);
		linecount++;
	}
	free(buffer), free_stack(&stack), fclose(file),	exit(exitstatus);
}
