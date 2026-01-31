/*
 * Copyright (c) 2026, Ian Moffett.
 * Provided under the BSD-3 clause.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "emul/soc.h"
#include "emul/file.h"

#define VERSION "0.0.1"

/* Run-time parameters */
static const char *firmware_path = NULL;

static void
help(void)
{
    printf(
        "---- the TPC64 emulator ----\n"
        "[-h]   Display this help menu\n"
        "[-v]   Display version\n"
        "[-f]   Path to firmware / BIOS\n"
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
    struct emul_file fw;

    if (soc_init(&soc) < 0) {
        perror("soc_init");
        return;
    }

    /* Attempt to open the BIOS we were provided */
    if (emul_file_open(firmware_path, O_RDONLY, &fw) < 0) {
        printf("fatal: failed to open firmware path\n");
        perror("emul_file_open");
        return;
    }

    /*
     * Now we must write the firmware to RAM.
     *
     * TODO: In the future, address 0 should be delegated by a bus
     *       control layer to some sort of SPI flash subsystem.
     */
    balloon_write(
        &soc.ram,
        0,
        emul_file_data(&fw),
        emul_file_size(&fw)
    );

    /* Bring up the SoC */
    soc_destroy(&soc);
}

int
main(int argc, char **argv)
{
    int opt;

    while ((opt = getopt(argc, argv, "hvf:")) != -1) {
        switch (opt) {
        case 'h':
            help();
            return -1;
        case 'v':
            version();
            return -1;
        case 'f':
            firmware_path = strdup(optarg);
            break;
        }
    }

    if (firmware_path == NULL) {
        printf("fatal: expected path to firmware / BIOS\n");
        return -1;
    }

    emulation_begin();
    return 0;
}
