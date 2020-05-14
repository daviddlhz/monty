#include "monty.h"
 
/**
 * openfile - function that reads a text file and prints
 *@FILENAME: is the rute of monty file
 * Return: Reading the file
 */
void openfile(char *FILENAME)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;
    FILE *fp = fopen(FILENAME, "r");
    stack_t *stack_list = NULL;
 
    if (!fp)
    {
        fprintf(stderr, "Error: Can't open file <%s>\n", FILENAME);
        exit(EXIT_FAILURE);
    }
 
    line_size = getline(&line_buf, &line_buf_size, fp);
 
    while (line_size >= 0)
    {
        line_count++;
        split_file(line_buf, &stack_list);
        line_size = getline(&line_buf, &line_buf_size, fp);
 
        if (!line_buf)
        {
            printf("Error: malloc failed\n");
            fclose(fp);
            exit(EXIT_FAILURE);
        }
    }
 
    free(line_buf);
    line_buf = NULL;
 
    fclose(fp);
}
