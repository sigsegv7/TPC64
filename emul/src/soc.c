/*
 * Copyright (c) 2026, Ian Moffett.
 * Provided under the BSD-3 clause.
 */

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
