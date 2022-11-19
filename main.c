#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "inputReader.h"
#include "sqlEngine.h"

int main(int argc, char* argv[])
{
    InputBuffer *input_buffer = new_input_buffer();
    while (true)
    {
        print_prompt();
        read_input(input_buffer);

        if (input_buffer->buffer[0] == '.')
        {
            switch (meta_command_invoke(input_buffer))
            {
                case META_COMMAND_SUCCESS:
                    continue;
                case META_COMMAND_UNRECOGNIZED:
                    printf("Unrecognized command '%s'\n", input_buffer->buffer);
                    continue;
            }
        }

        Statement statement;
        switch (prepare_statement(input_buffer, &statement))
        {
            case PREPARE_SUCCESS:
                break;
            case PREPARE_UNRECOGNIZED:
                printf("Unrecognized keyword '%s'\n", input_buffer->buffer);
                continue;
        }

        execute_statement(&statement);
        printf("Executed\n");
    }

    return 0;
}