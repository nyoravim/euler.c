#ifndef PROBLEM_H
#define PROBLEM_H

typedef struct problem {
    int (*callback)(const char* data, size_t size);

    char* input_data;
    size_t input_size;
} problem_t;

void problem_load_input(problem_t* problem, FILE* input);
int problem_execute(problem_t* problem);

#endif
