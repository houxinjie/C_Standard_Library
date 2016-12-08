#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void _Assert(const char *statement, const char *filename, const char *line, const char *function_name) {
    fputs("Assertion failed: (", stderr);
    fputs(statement, stderr);
    fputs("), function ", stderr);
    fputs(function_name, stderr);
    fputs(", file ", stderr);
    fputs(filename, stderr);
    fputs(", line ", stderr);
    fputs(line, stderr);
    fputs(".\n", stderr);
    abort();
}
