/*
 * Copyright (c) 2026, Ian Moffett.
 * Provided under the BSD-3 clause.
 */

#include <errno.h>
#include <emul/soc.h>
#include <emul/cpu.h>

void
soc_reset(struct soc_package *soc)
{
    if (soc == NULL) {
        return;
    }

    cpu_reset(&soc->pd[0]);
}

int
soc_init(struct soc_package *soc)
{
    int error;

    if (soc == NULL) {
        errno = -EINVAL;
        return -1;
    }

    error = balloon_new(&soc->ram, 8, MAXIMUM_RAM);
    if (error < 0) {
        return -1;
    }

    soc_reset(soc);
    return 0;
}

void
soc_destroy(struct soc_package *soc)
{
    if (soc == NULL) {
        return;
    }

    balloon_destroy(&soc->ram);
}
