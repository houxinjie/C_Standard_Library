#include <assert.h>
#include "errno.h"
#include <math.h>
#include <stdio.h>

int main() {
    assert(errno == 0);
    perror("No error reported as");
    errno = ERANGE;
    assert(errno == ERANGE);
    perror("Range error reported as");
    puts("SUCCESS testing <errno.h>");
    return (0);
}
