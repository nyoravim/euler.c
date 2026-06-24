#include "pch.h"
#include "problem.h"

void problem_load_input(problem_t* problem, FILE* input) {
    char buffer[512];
    unsigned long read;

    free(problem->input_data);
    problem->input_data = NULL;

    read = fread(buffer, 1, sizeof(buffer), input);
    while (read > 0) {
        problem->input_data = realloc(problem->input_data, problem->input_size + read);
        memcpy(problem->input_data + problem->input_size, buffer, read);
        problem->input_size += read;

        read = fread(buffer, 1, sizeof(buffer), input);
    };
}

int problem_execute(problem_t* problem) {
    return problem->callback(problem->input_data, problem->input_size);
}
