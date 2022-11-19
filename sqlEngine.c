#include "sqlEngine.h"

#include <stdio.h>
#include <string.h>

MetaCommandResult meta_command_invoke(InputBuffer *input_buffer)
{
    if (!strcmp(input_buffer->buffer, ".exit"))
    {
        delete_input_buffer(input_buffer);
        exit(EXIT_FAILURE);
    }
    else
    {
        return META_COMMAND_UNRECOGNIZED;
    }
}

PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement)
{
    if (!strncmp(input_buffer->buffer, "insert", 6))
    {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    if (!strcmp(input_buffer->buffer, "select"))
    {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNIZED;
}

void execute_statement(Statement *statement)
{
    switch (statement->type) {
        case STATEMENT_INSERT:
            printf("insert\n");
            return;
        case STATEMENT_SELECT:
            printf("select\n");
            return;
        default:
            return;
    }
}