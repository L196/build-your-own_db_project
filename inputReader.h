#pragma once

#include <stdlib.h>

typedef struct {
    char *buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

void print_prompt();
InputBuffer * new_input_buffer();
void read_input(InputBuffer *input_buffer);
void delete_input_buffer(InputBuffer *input_buffer);