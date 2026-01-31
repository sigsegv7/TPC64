/*
 * Copyright (c) 2026, Ian Moffett.
 * Provided under the BSD-3 clause.
 */

#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include "emul/cpu.h"

/*
 * Table used to convert register ID constants to
 * human readable strings.
 */
static const char *regtab[] = {
    [REG_R0] = "r0",
    [REG_R1] = "r1",
    [REG_R2] = "r2",
    [REG_R3] = "r3",
    [REG_R4] = "r4",
    [REG_R5] = "r5",
    [REG_R6] = "r6",
    [REG_R7] = "r7",
    [REG_A0] = "a0",
    [REG_A1] = "a1",
    [REG_A2] = "a2",
    [REG_A3] = "a3",
    [REG_A4] = "a4",
    [REG_A5] = "a5",
    [REG_A6] = "a6",
    [REG_A7] = "a7",
    [REG_SP] = "sp",
    [REG_FP] = "fp",
    [REG_ZERO] = "zero",
    [REG_TTBR] = "ttbr",
    [REG_PC]  = "pc"
};

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

void
cpu_dump(struct cpu_domain *cpu)
{
    if (cpu == NULL) {
        return;
    }

    /* Dump every register */
    for (size_t i = 0; i < REG_MAX; ++i) {
        if (i > 0 && (i % 2) == 0) {
            printf("\n");
        }

        printf("%s=%016zX ", regtab[i], cpu->regbank[i]);
    }

    printf("\n");
}
