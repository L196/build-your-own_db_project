#pragma once

#include "inputReader.h"

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED
} MetaCommandResult;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED
} PrepareResult;

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef struct {
    StatementType type;
} Statement;

MetaCommandResult meta_command_invoke(InputBuffer *input_buffer);
PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement);
void execute_statement(Statement *statement);
