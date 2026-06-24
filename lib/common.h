#ifndef COMMON_H
#define COMMON_H

#include "pch.h"
#include "problem.h"

#ifdef IMPLEMENT_STUB

int solve(const char* data, size_t size);

int main(int argc, const char** argv) {
    problem_t problem;
    memset(&problem, 0, sizeof(problem_t));
    problem.callback = solve;

    problem_load_input(&problem, stdin);
    int ret = problem_execute(&problem);

    free(problem.input_data);
    return ret;
}

#endif
#endif
