/*
 * Copyright (c) 2026, Ian Moffett.
 * Provided under the BSD-3 clause.
 */

#ifndef EMUL_CPU_H
#define EMUL_CPU_H 1

#include <stdint.h>
#include <stddef.h>

/*
 * Valid registers for the processor
 */
typedef enum {
    REG_R0,
    REG_R1,
    REG_R2,
    REG_R3,
    REG_R4,
    REG_R5,
    REG_R6,
    REG_R7,
    REG_A0,
    REG_A1,
    REG_A2,
    REG_A3,
    REG_A4,
    REG_A5,
    REG_A6,
    REG_A7,
    REG_SP,
    REG_FP,
    REG_ZERO,
    REG_TTBR,
    REG_PC,
    REG_MAX,
    REG_BAD = 0xFF
} reg_t;

/*
 * Represents a processing domain
 *
 * @regbank: Register bank
 */
struct cpu_domain {
    uint64_t regbank[REG_MAX];
};

/*
 * Reset a processing domain
 *
 * @cpu: Processing domain to reset
 */
void cpu_reset(struct cpu_domain *cpu);

#endif  /* !EMUL_CPU_H */
