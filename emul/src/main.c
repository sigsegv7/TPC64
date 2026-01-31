/*
 * Copyright (c) 2026, Ian Moffett.
 * Provided under the BSD-3 clause.
 */

#include <stdio.h>
#include <unistd.h>

#define VERSION "0.0.1"

static void
help(void)
{
    printf(
        "---- the TPC64 emulator ----\n"
        "[-h]   Display this help menu\n"
        "[-v]   Display version\n"
        "----------------------------\n"
    );
}

static void
version(void)
{
    printf(
        "---- the TPC64 emulator ----\n"
        "Copyright (c) 2026, Ian Moffett\n"
        "Version %s\n"
        "----------------------------\n",
        VERSION
    );
}

int
main(int argc, char **argv)
{
    int opt;

    while ((opt = getopt(argc, argv, "hv")) != -1) {
        switch (opt) {
        case 'h':
            help();
            return -1;
        case 'v':
            version();
            return -1;
        }
    }

    return 0;
}
