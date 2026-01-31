/*
 * Copyright (c) 2026, Ian Moffett.
 * Provided under the BSD-3 clause.
 */

#ifndef EMUL_SOC_H
#define EMUL_SOC_H 1

#define MAXIMUM_RAM (0x40000000UL * 2) /* 2 GiB */

#include <stdint.h>
#include "emul/cpu.h"
#include "emul/balloon.h"

/*
 * Represents the System-on-Chip (SoC) package encapsulating
 * the processing domains among other components.
 *
 * @pd: Processing domains
 * @ram: Represents external RAM (e.g., DDR)
 */
struct soc_package {
    struct cpu_domain pd[1];
    struct balloon_mem ram;
};

/*
 * Initialize the System-on-Chip package
 *
 * @soc: SoC to initialize
 */
int soc_init(struct soc_package *soc);

/*
 * Destroy the System-on-Chip package
 *
 * @soc: SoC to destroy
 */
void soc_destroy(struct soc_package *soc);

/*
 * Reset the System-on-Chip package
 *
 * @soc: SoC to reset
 */
void soc_reset(struct soc_package *soc);

#endif  /* !EMUL_SOC_H */
