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
		linesize = getline(&buffer, &buffsize, file);
	}
	free(buffer);
	fclose(file);
	return (EXIT_SUCCESS);
}
