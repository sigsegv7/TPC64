/*
 * Copyright (c) 2026, Ian Moffett.
 * Provided under the BSD-3 clause.
 */

#ifndef EMUL_SOC_H
#define EMUL_SOC_H 1

#include <stdint.h>
#include "emul/cpu.h"

/*
 * Represents the System-on-Chip (SoC) package encapsulating
 * the processing domains among other components.
 *
 * @pd: Processing domains
 */
struct soc_package {
    struct cpu_domain pd[1];
};

/*
 * Reset the System-on-Chip package
 *
 * @soc: SoC to reset
 */
void soc_reset(struct soc_package *soc);

#endif  /* !EMUL_SOC_H */
