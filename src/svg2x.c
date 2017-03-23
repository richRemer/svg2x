#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

static int verbose = 0;
static int relative = 0;
static char* output = NULL;

static const char* flags = "vqo:r";
static struct option options[] = {
    {"verbose",     no_argument,        &verbose,   1},
    {"quiet",       no_argument,        &verbose,   0},
    {"relative",    no_argument,        &relative,  1},
    {"output",      required_argument,  0,          'o'},
};

int main(int argc, char* argv[]) {
    int i = 0;
    char f;

    while (1) {
        f = getopt_long(argc, argv, flags, options, &i);

        if (f == -1) break;

        switch (f) {
            case 0: printf("opt %s\n", options[i].name); break;
            case 'v': verbose = 1; break;
            case 'q': verbose = 0; break;
            case 'r': relative = 1; break;
            case 'o': output = strdup(optarg); break;
            case '?': break;
            default: abort();
        }
    }

    if (verbose) printf("verbose\n");
    if (relative) printf("relative\n");
    if (output) printf("output: %s\n", output);

    return 0;
}
