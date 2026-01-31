/*
 * Copyright (c) 2026, Ian Moffett.
 * Provided under the BSD-3 clause.
 */

#include <stdio.h>
#include <unistd.h>
#include "emul/soc.h"

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

static void
emulation_begin(void)
{
    struct soc_package soc;

    if (soc_init(&soc) < 0) {
        perror("soc_init");
        return;
    }

    /* Bring up the SoC */
    soc_destroy(&soc);
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

    emulation_begin();
    return 0;
}
