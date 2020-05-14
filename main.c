#include "monty.h"
/**
 * main - Init the monty interprete project
 *@argv: return of size of argv
 *@argc: return of values of program
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	char *FILENAME;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	FILENAME = argv[1];
	openfile(FILENAME);
	return (0);
}
