#include "inputReader.h"

#include <stdio.h>
#include <string.h>

ssize_t myGetline(char **lineptr, size_t *n, FILE *stream);

#ifdef _WIN32
    #define getline(buffer, buffer_size, input_source) myGetline(buffer, buffer_size, input_source)
#endif

void print_prompt() { printf("db -> "); }

InputBuffer * new_input_buffer() {
    InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

void read_input(InputBuffer *input_buffer)
{
    ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    if (bytes_read <= 0)
    {
        printf("Error while reading input\n");
        exit(EXIT_FAILURE);
    }

    input_buffer->input_length = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = 0;
}

void delete_input_buffer(InputBuffer *input_buffer)
{
    free(input_buffer->buffer);
    free(input_buffer);
}

ssize_t myGetline(char **lineptr, size_t *n, FILE *stream)
{
    char local_buffer[100];
    int c = 0;
    unsigned i = 0;

    while ((c = fgetc(stdin)) != '\n')
    {
        local_buffer[i++] = c;
    }
    local_buffer[i++] = '\0';

    *lineptr = (char *)malloc(i);
    strcpy(*lineptr, local_buffer);

    return i;
}