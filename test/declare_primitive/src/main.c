#include <include/test.h>

int cortomain(int argc, char *argv[]) {
    int result = 0;
    test_Runner runner = test_Runner__create(NULL, NULL, "declare_primitive", argv[0], (argc > 1) ? argv[1] : NULL);
    if (!runner) return -1;
    if (ut_ll_count(runner->failures)) {
        result = -1;
    }
    corto_delete(runner);
    return result;
}
