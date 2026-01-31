/*
 * Copyright (c) 2026, Ian Moffett.
 * Provided under the BSD-3 clause.
 */

#include <stdint.h>
#include <errno.h>
#include "emul/cpu.h"

/*
 * Initiate a reset for a processing domain
 *
 * @cpu: Processing domain to reset
 */
void
cpu_reset(struct cpu_domain *cpu)
{
    if (cpu == NULL) {
        return;
    }

    /*
     * Initialize general and ABI registers to their
     * initial reset value as per the TPC64 spec.
     */
    for (reg_t r = 0; r < REG_MAX; ++r) {
        cpu->regbank[r] = (r <= REG_SP)
            ? 0x1C1A1C1A1C1A1C1A
            : 0x0000000000000000;
    }
}
