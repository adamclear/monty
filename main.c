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
	char **command = malloc(sizeof(char *) * buffsize);
	char *parse = NULL;
	int x;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	linesize = getline(&buffer, &buffsize, file);
	while (linesize >= 0)
	{
		linecount++;
		printf("%s", buffer);
		parse = strtok(buffer, " \t\n");
		for (x = 0; parse != NULL; x++)
		{
			command[x] = parse;
			parse = strtok(NULL, " \t\n");
			printf("%s\n", command[x]);
		}
		linesize = getline(&buffer, &buffsize, file);
	}
	free(buffer);
	free(command);
	fclose(file);
	return (EXIT_SUCCESS);
}
